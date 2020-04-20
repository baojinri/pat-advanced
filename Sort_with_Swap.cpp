#include <iostream>

int a[100010];

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        a[x] = i;
    }
    int count = 0;
    while (a[0] != 0)
    {
        int temp = a[0];
        a[0] = a[a[0]];
        a[temp] = temp;
        count++;
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] != i)
        {
            a[0] = a[i];
            a[i] = 0;
            count++;
            while (a[0] != 0)
            {
                int temp = a[0];
                a[0] = a[a[0]];
                a[temp] = temp;
                count++;
            }
        }
    }
    std::cout << count;
    return 0;
}