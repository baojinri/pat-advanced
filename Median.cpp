#include <iostream>
long int a[200010];

int main()
{
    std::ios::sync_with_stdio(false);
    long int n, m;
    std::cin >> n;
    for (long int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    std::cin >> m;
    long int median = (m + n + 1) / 2;
    long int j = 0;
    long int count = 0;
    long int b;
    for (long int i = 0; i < m; i++)
    {
        std::cin >> b;
        while (a[j] < b && j < n)
        {
            count++;
            if (count == median)
            {
                std::cout << a[j];
                return 0;
            }
            j++;
        }
        count++;
        if (count == median)
        {
            std::cout << b;
            return 0;
        }
    }
    while (true)
    {
        count++;
        if (count == median)
        {
            std::cout << a[j];
            return 0;
        }
        j++;
    }
    return 0;
}