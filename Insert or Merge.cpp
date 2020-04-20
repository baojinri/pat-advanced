#include <algorithm>
#include <cmath>
#include <iostream>
int a[110], b[110], c[110];
int n;

int insert(int n)
{
    for (int i = n; i > 0; i--)
    {
        if (a[i] < a[i - 1])
        {
            int temp = a[i];
            a[i] = a[i - 1];
            a[i - 1] = temp;
        }
    }

    return 0;
}

int merge(int x)
{
    int i = 0, j = x;
    while (j < n)
    {
        std::sort(b + i, b + j);
        i = j;
        j += x;
    }
    std::sort(b + i, b + n);
    return 0;
}

int main()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        b[i] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> c[i];
    }
    int i;
    for (i = 1; i < n; i++)
    {
        insert(i);
        int j;
        for (j = 0; j < n; j++)
        {
            if (a[j] != c[j])
                break;
        }
        if (j == n)
        {
            break;
        }
    }
    if (i < n)
    {
        std::cout << "Insertion Sort" << std::endl;
        insert(i + 1);
        for (int j = 0; j < n - 1; j++)
        {
            std::cout << a[j] << " ";
        }
        std::cout << a[n - 1];
        return 0;
    }
    std::cout << "Merge Sort" << std::endl;
    i = 1;
    while (pow(2, i) < n)
    {
        merge(pow(2, i));
        int j;
        for (j = 0; j < n; j++)
        {
            if (b[j] != c[j])
                break;
        }
        if (j == n)
        {
            break;
        }
        i++;
    }
    merge(pow(2, i + 1));
    for (int j = 0; j < n - 1; j++)
    {
        std::cout << b[j] << " ";
    }
    std::cout << b[n - 1];
    return 0;
}