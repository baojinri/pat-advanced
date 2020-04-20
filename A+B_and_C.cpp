#include <iostream>

int main()
{
    int n;
    long long a, b, c,ans;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a >> b >> c;
        ans = a + b;
        if (a > 0 && b > 0 && ans < 0)
        {
            std::cout << "Case #" << i + 1 << ": true" << std::endl;
        }
        else if (a < 0 && b < 0 && ans >= 0)
        {
            std::cout << "Case #" << i + 1 << ": false" << std::endl;
        }
        else if (ans > c)
        {
            std::cout << "Case #" << i + 1 << ": true" << std::endl;
        }
        else
        {
            std::cout << "Case #" << i + 1 << ": false" << std::endl;
        }
    }
    return 0;
}