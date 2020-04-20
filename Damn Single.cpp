#include <algorithm>
#include <iostream>
int a[100000];
int b[100000];
int visited[100000] = {0};
int ans[100000];
int count = 0;

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < 100000; i++)
    {
        a[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        a[x] = y;
        a[y] = x;
    }
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++)
    {
        std::cin >> b[i];
        visited[b[i]] = 1;
    }
    for (int i = 0; i < k; i++)
    {
        if (a[b[i]] == -1)
        {
            ans[count++] = b[i];
        }
        else
        {
            if (visited[a[b[i]]] == 0)
                ans[count++] = b[i];
        }
    }
    std::sort(ans, ans + count);
    std::cout << count << std::endl;
    for (int i = 0; i < count; i++)
    {
        printf("%05d", ans[i]);
        if (i != count - 1)
            std::cout << " ";
    }

    return 0;
}