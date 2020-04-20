#include <cmath>
#include <iostream>
#include <string>
std::string num[15] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
std::string num2[15] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int main()
{
    int n;
    std::cin >> n;
    std::getchar();
    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::getline(std::cin, s);
        if (s[0] >= '0' && s[0] <= '9')
        {
            int a = 0;
            for (int i = 0; i < s.size(); i++)
            {
                a += (s[i] - '0') * pow(10, s.size() - 1 - i);
            }
            int x = 0, y = 0;
            x = a / 13;
            y = a % 13;
            if (x != 0 && y != 0)
            {
                std::cout << num2[x] << " " << num[y] << std::endl;
            }
            else if (x != 0 && y == 0)
            {
                std::cout << num2[x] << std::endl;
            }
            else if (y != 0 && x == 0)
            {
                std::cout << num[y] << std::endl;
            }
            else
            {
                std::cout << num[0] << std::endl;
            }
        }
        else
        {
            if (s.size() == 3)
            {
                int j;
                for (j = 0; j < 13; j++)
                {
                    if (num[j] == s)
                    {
                        std::cout << j<<std::endl;
                        break;
                    }
                }
                if (j == 13)
                {
                    for (j = 0; j < 13; j++)
                    {
                        if (num2[j] == s)
                        {
                            std::cout << j*13<<std::endl;
                            break;
                        }
                    }
                }
            }
            else
            {
                std::string s1, s2;
                for (int j = 0; j < 3; j++)
                {
                    s1 += s[j];
                }
                for (int j = 4; j < 7; j++)
                {
                    s2 += s[j];
                }
                int x = 0, y = 0;
                for (int j = 0; j < 13; j++)
                {
                    if (num2[j] == s1)
                        x = j;
                }
                for (int j = 0; j < 13; j++)
                {
                    if (num[j] == s2)
                        y = j;
                }
                std::cout << 13*x + y << std::endl;
            }
        }
    }

    return 0;
}