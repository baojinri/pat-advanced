#include <algorithm>
#include <iostream>

int p[100010], q[100010];

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i];
    }
    std::sort(p, p + n);
    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        std::cin >> q[i];
    }
    std::sort(q,q + m);
    int it1 = 0, it2 = 0;
    int sum = 0;
    while (p[it1] < 0 && q[it2] < 0)
    {
        sum += p[it1] * q[it2];
        it1++;
        it2++;
    }
    it1 = n - 1;
    it2 = m - 1;
    while (p[it1] > 0 && q[it2] > 0)
    {
        sum += p[it1] * q[it2];
        it1--;
        it2--;
    }
    std::cout << sum;
    return 0;
}