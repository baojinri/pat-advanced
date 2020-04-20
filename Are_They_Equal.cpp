#include <cmath>
#include <iostream>

int main()
{
    int n;
    double a, b;
    std::cin >> n >> a >> b;
    int i = -101;
    while (true)
    {
        if (a / pow(10, i) < 1)
            break;
        i++;
    }
    int asize = i;
    int x, y;
    x = a / pow(10, (asize - n));
    i = -101;
    while (true)
    {
        if (b / pow(10, i) < 1)
            break;
        i++;
    }
    int bsize = i;
    y = b / pow(10, (bsize - n));
    if (x == y)
    {
        if (asize != 0)
            std::cout << "YES"
                      << " 0." << x << "*10^" << asize;
        else
            std::cout << "YES"
                      << " 0." << x;
    }
    else
    {
        std::cout << "NO";
        if (asize != 0)
            std::cout << " 0." << x << "*10^" << asize;
        else
            std::cout << " 0." << x;
        if (bsize != 0)
            std::cout << " 0." << y << "*10^" << bsize;
        else
            std::cout << " 0." << y;
    }

    return 0;
}