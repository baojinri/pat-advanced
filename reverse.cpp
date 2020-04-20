#include <cmath>
#include <iostream>
#include <string>

int reverse(int n, int d)
{
    std::string str = "";
    while (n > 0)
    {
        str = str + std::to_string(n % d);
        n = n / d;
    }
    int sum = 0;
    int k = str.size();
    for (int i = 0; i < k; i++)
    {
        sum = sum + pow(d, k - i - 1) * (str[i] - '0');
    }
    return sum;
}

bool judge(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, d;
    while (true)
    {
        std::cin >> n;
        if (n < 0)
            break;
        std::cin >> d;
        int sum = reverse(n, d);
        if (judge(n) && judge(sum))
        {
            std::cout << "Yes" << std::endl;
        }
        else
        {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}