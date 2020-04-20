#include <iostream>

bool isprime(long int n)
{
    int i;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
            break;
    }
    if (i == n)
    {
        return true;
    }
    return false;
}

int main()
{
    long int n;
    std::cin >> n;
    if (n == 1)
    {
        std::cout << "1=1";
        return 0;
    }
    int i;
    for (i = 2; i < n + 1; i++)
    {
        if (isprime(i) && n % i == 0)
            break;
    }
    std::cout << n << "=";
    int count = 0;
    while (n % i == 0)
    {
        n = n / i;
        count++;
    }
    if (count == 1)
    {
        std::cout << i;
    }
    else if (count > 1)
    {
        std::cout << i << "^" << count;
    }
    for (i = i + 1; i < n + 1; i++)
    {
        if (isprime(i))
        {
            int count = 0;
            while (n % i == 0)
            {
                n = n / i;
                count++;
            }
            if (count == 1)
            {
                std::cout << "*" << i;
            }
            else if (count > 1)
            {
                std::cout << "*" << i << "^" << count;
            }
        }
    }

    return 0;
}