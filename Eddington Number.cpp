#include <algorithm>
#include <iostream>
int a[100010];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    std::sort(a, a + n, cmp);
    int i;
    for (i = 0; i < n; i++)
    {
        if (i + 1 >= a[i])
            break;
    }
    std::cout << i;
    return 0;
}