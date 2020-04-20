#include <algorithm>
#include <iostream>
int a[100010];
int b[100010];
int c[1000];
int count = 0;

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        b[i] = a[i];
    }
    std::sort(a, a + n);
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i] && b[i] > max)
        {
            c[count++] = a[i];
        }
        if (max < b[i])
        {
            max = b[i];
        }
    }
    std::sort(c, c + count);
    if (count != 0)
    {
        std::cout << count << std::endl;
        for (int i = 0; i < count; i++)
        {
            std::cout << c[i];
            if (i != count - 1)
                std::cout << " ";
        }
    }
    else
    {
        std::cout << 0 << std::endl;
        std::cout << std::endl;
    }
    return 0;
}