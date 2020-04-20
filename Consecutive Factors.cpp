#include <cmath>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    int max = 0;
    int flag = 1;
    for (int i = 2; i <= sqrt(n); i++)
    {
        int temp = i;
        int count = 0;
        int j = i;
        while (n % temp == 0)
        {
            count++;
            j++;
            temp = temp * j;
        }
        if (count > max)
        {
            max = count;
            flag = i;
        }
    }
    if (max > 0)
    {
        std::cout << max << std::endl;
        for (int i = 0; i < max; i++)
        {
            std::cout << i + flag;
            if (i != max - 1)
                std::cout << "*";
        }
    }
    else
    {
        std::cout << 1 << std::endl
                  << n;
    }

    return 0;
}