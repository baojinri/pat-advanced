#include <cmath>
#include <iostream>
#include <string>

int main()
{
    std::string str[3];
    int count = 0;
    char word;
    word = std::getchar();
    while (word != '\n')
    {
        if (word != '.' && word != 'E')
        {
            str[count] += word;
        }
        else
        {
            count++;
        }
        word = std::getchar();
    }
    if (str[2] == "00")
    {
        if (str[0][0] = '+')
        {
            str[0].erase(str[0].begin());
        }
        std::cout << str[0] << "." << str[1];
        return 0;
    }

    int i;

    if (str[2][0] == '+')
    {
        int x = 0;
        str[2].erase(str[2].begin());
        for (int j = str[2].size() - 1; j > -1; j--)
        {
            x += (str[2][j] - '0') * pow(10, str[2].size() - 1 - j);
        }
        if (str[0][0] == '+')
            str[0].erase(str[0].begin());
        if (x >= str[1].size())
        {

            std::cout << str[0] << str[1];
            for (int i = 0; i < x - str[1].size(); i++)
            {
                std::cout << 0;
            }
        }
        else
        {
            std::cout << str[0];
            for (i = 0; i < x; i++)
            {
                std::cout << str[1][i];
            }
            std::cout << ".";
            for (i; i < str[1].size(); i++)
            {
                std::cout << str[1][i];
            }
        }
    }
    else
    {
        int x = 0;
        str[2].erase(str[2].begin());
        for (int j = str[2].size() - 1; j > -1; j--)
        {
            x += (str[2][j] - '0') * pow(10, str[2].size() - 1 - j);
        }
        if (str[0][0] == '-')
            std::cout << "-";

        std::cout << "0.";
        for (int i = 0; i < x - 1; i++)
        {
            std::cout << 0;
        }
        std::cout << str[0][1] << str[1];
    }
    return 0;
}