#include <iostream>
int a[100010];

int main()
{
    int n;
    std::cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i + 2];
        sum += a[i + 2];
        a[i + 2] = sum;
    }
    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        if (y < x)
        {
            int temp = x;
            x = y;
            y = temp;
        }
        std::cout << (a[y] - a[x] < a[n + 1] - a[y] + a[x] ? a[y] - a[x] : a[n + 1] - a[y] + a[x])
                  << std::endl;
    }

    return 0;
}