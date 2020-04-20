#include <cstdio>
#include <iostream>

int main()
{
    int a = 0, b = 0, c = 0;
    int m, n, t;
    for (int i = 0; i < 2; i++)
    {
        scanf("%d.%d.%d", &m, &n, &t);
        a += m;
        b += n;
        c += t;
    }
    int jw = 0;
    if (c > 28)
    {
        c = c - 29;
        jw = 1;
    }
    b = b + jw;
    jw = 0;
    if (b > 16)
    {
        b = b - 17;
        jw = 1;
    }
    a = a + jw;
    std::cout << a << "." << b << "." << c << std::endl;

    return 0;
}