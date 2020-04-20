#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    std::string s[110];
    int n;
    std::cin >> n;
    std::getchar();
    int min = 100000;
    for (int i = 0; i < n; i++)
    {
        std::getline(std::cin, s[i]);
        std::reverse(s[i].begin(), s[i].end());
        if (s[i].size() < min)
            min = s[i].size();
    }
    int flag = 0;
    for (int i = 0; i < min; i++)
    {
        int j;
        for (j = 1; j < n; j++)
        {
            if (s[j - 1][i] != s[j][i])
            {
                break;
            }
        }
        if (j == n)
        {
            flag++;
        }
        else
        {
            break;
        }
    }
    if (flag != 0)
    {
        std::string str = "";
        for (int i = 0; i < flag; i++)
        {
            str = s[0][i] + str;
        }
        std::cout << str;
    }
    else
    {
        std::cout << "nai";
    }

    return 0;
}