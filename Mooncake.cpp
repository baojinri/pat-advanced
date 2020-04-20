#include <algorithm>
#include <iomanip>
#include <iostream>
struct Mooncake
{
    double amant;
    double totalp;
    double price;
};
Mooncake m[1010];

bool cmp(Mooncake a, Mooncake b)
{
    return a.price > b.price;
}

int main()
{
    int n, d;
    std::cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        std::cin >> m[i].amant;
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> m[i].totalp;
        m[i].price = m[i].totalp / m[i].amant;
    }
    std::sort(m, m + n, cmp);
    double total = 0;
    for (int i = 0; i < n; i++)
    {
        if (d >= m[i].amant)
        {
            d -= m[i].amant;
            total += m[i].totalp;
        }
        else if (d < m[i].amant)
        {
            total += d * m[i].price;
            d = 0;
        }
        if (d == 0)
            break;
    }

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << total;
    return 0;
}