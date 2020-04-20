#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

int main()
{
    std::string a;
    std::cin >> a;
    int c[4];
    int length = a.size();
    for (int i = 0; i < length; i++)
    {
        c[i] = a[i] - '0';
    }
    if (length == 3)
    {
        c[3] = 0;
    }
    std::sort(c, c + 4);
    int x, y, z;
    x = c[3] * pow(10, 3) + c[2] * pow(10, 2) + c[1] * pow(10, 1) + c[0];
    y = c[0] * pow(10, 3) + c[1] * pow(10, 2) + c[2] * pow(10, 1) + c[3];
    z = x - y;
    std::cout << x << " - ";
    if (y < 1000)
    {
        std::cout << 0;
    }
    if (y < 100)
    {
        std::cout << 0;
    }
    if (y < 10)
    {
        std::cout << 0;
    }
    std::cout << y << " = ";
    if (z < 1000)
    {
        std::cout << 0;
    }
    if (z < 100)
    {
        std::cout << 0;
    }
    if (z < 10)
    {
        std::cout << 0;
    }
    std::cout << z << std::endl;
    if (z == 0)
    {
        return 0;
    }
    while (z != 6174)
    {
        a = std::to_string(z);
        length = a.size();
        for (int i = 0; i < length; i++)
        {
            c[i] = a[i] - '0';
        }
        if (length == 3)
        {
            c[3] = 0;
        }
        std::sort(c, c + 4);
        x = c[3] * pow(10, 3) + c[2] * pow(10, 2) + c[1] * pow(10, 1) + c[0];
        y = c[0] * pow(10, 3) + c[1] * pow(10, 2) + c[2] * pow(10, 1) + c[3];
        z = x - y;
        std::cout << x << " - ";
        if (y < 1000)
        {
            std::cout << 0;
        }
        if (y < 100)
        {
            std::cout << 0;
        }
        if (y < 10)
        {
            std::cout << 0;
        }
        std::cout << y << " = ";
        if (z < 1000)
        {
            std::cout << 0;
        }
        if (z < 100)
        {
            std::cout << 0;
        }
        if (z < 10)
        {
            std::cout << 0;
        }
        std::cout << z << std::endl;
    }

    return 0;
}