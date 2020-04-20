#include <algorithm>
#include <iostream>
int ans[15];
int num[50010] = {0};
int a[50010];

bool cmp(int a, int b)
{
    if (num[a] == num[b])
        return a < b;

    return num[a] > num[b];
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n, k;
    std::cin >> n >> k;
    int count = 0;
    std::cin >> ans[count++];
    num[ans[count - 1]]++;
    for (int i = 1; i < n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        std::cout << a[i] << ": ";
        for (int j = 0; j < count; j++)
        {
            std::cout << ans[j];
            if (j < count - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
        num[a[i]]++;
        int j;
        for (j = 0; j < count; j++)
        {
            if (ans[j] == a[i])
                break;
        }
        if (j == count)
        {
            if (count < k)
                ans[count++] = a[i];
            else
            {
                if (num[ans[k - 1]] < num[a[i]] || (num[ans[k - 1]] == num[a[i]] && ans[k - 1] > a[i]))
                    ans[k - 1] = a[i];
            }
        }
        std::sort(ans, ans + count, cmp);
    }
    return 0;
}