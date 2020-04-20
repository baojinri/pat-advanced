#include <algorithm>
#include <iostream>
#include <vector>
std::vector<int> ans;
int n, m, temp[10010], a[10010];

int dfs(int v, int deep, int sum)
{
    temp[deep] = a[v];
    sum += a[v];
    deep++;
    if (sum == m)
    {
        for (int i = 0; i < deep; i++)
        {
            ans.push_back(temp[i]);
        }
        return 0;
    }
    for (int i = v + 1; i < n; i++)
    {
        if (sum + a[i] > m)
            break;
        dfs(i, deep, sum);
        if (ans.size() != 0)
            break;
    }
    return 0;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        a[i] = temp;
    }
    std::sort(a, a + n);
    ans.clear();
    for (int i = 0; i < n; i++)
    {
        if (a[i] > m)
            break;
        dfs(i, 0, 0);
        if (ans.size() != 0)
            break;
    }
    if (ans.size() == 0)
        printf("No Solution");
    else
    {
        for (int i = 0; i < ans.size(); i++)
        {
            printf("%d", ans[i]);
            if (i != ans.size() - 1)
                printf(" ");
        }
    }
    return 0;
}