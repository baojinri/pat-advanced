#include<iostream>
#include<algorithm>
double a[10010];

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    std::sort(a, a + n);
    double sum = a[0];
    for (int i = 1; i < n; i++)
    {
        sum = (sum) / 2 + (a[i]) / 2;
    }
    std::cout << int(sum);

    return 0;
}