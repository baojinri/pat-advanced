#include <algorithm>
#include <iostream>
long long a[100010];

int main()
{
    int n;
    long long p;
    std::cin >> n >> p;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    std::sort(a, a + n);
    int i = 0, j = 0;
    while (j < n && a[j] <= a[i] * p)
    {
        j++;
    }
    j--;
    int max = j - i + 1;
    while (j < n)
    {
        i++;
        while (j < n && a[j] <= a[i] * p)
        {
            j++;
        }
        j--;
        if (max < j - i + 1)
        {
            max = j - i + 1;
        }
    }
    std::cout << max;
    return 0;
}