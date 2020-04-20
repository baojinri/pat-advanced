#include <algorithm>
#include <iostream>
int a[100010];

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    int n1 = n / 2;
    int n2 = n - n1;
    std::sort(a, a + n);
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n1; i++)
    {
        sum1 += a[i];
    }
    for (int i = n1; i < n; i++)
    {
        sum2 += a[i];
    }
    std::cout << n2 - n1 << " " << sum2 - sum1;
    return 0;
}