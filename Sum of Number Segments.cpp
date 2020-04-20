#include <iomanip>
#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    double ans = 0;
    for (int i = 1; i < n + 1; i++)
    {
        double temp;
        std::cin >> temp;
        ans += temp * i * (n + 1 - i);
    }
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << ans << std::endl;
    return 0;
}