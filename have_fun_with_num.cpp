#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;
    int num[10] = {0};
    int count = str.size();
    int m = 0, n = 0;
    int jw = 0;
    for (int i = count - 1; i > -1; i--)
    {
        m = str[i] - '0';
        n = m * 2;
        num[m] += 1;
        if (n >= 10)
        {
            n -= 10;
            num[n + jw] -= 1;
            str[i] = n + jw + '0';
            jw = 1;
        }
        else
        {
            num[n + jw] -= 1;
            str[i] = n + jw + '0';
            jw = 0;
        }
    }
    if (jw == 1)
    {
        std::cout << "No" << std::endl;
        std::cout << jw << str;
    }
    else
    {
        int i;
        for (i = 0; i < 10; i++)
        {
            if (num[i] != 0)
                break;
        }

        if (i == 10)
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
        std::cout << str;
    }

    return 0;
}