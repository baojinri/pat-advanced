#include <iostream>
int a[110], b[110], c[110];

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

int heap(int m, int n)
{
    int p = m;
    while (p * 2 + 1 < n)
    {
        int temp;
        if (p * 2 + 2 < n)
        {
            temp = b[p * 2 + 1] > b[p * 2 + 2] ? p * 2 + 1 : p * 2 + 2;
        }
        else
            temp = p * 2 + 1;
        if (b[temp] > b[p])
        {
            int x = b[temp];
            b[temp] = b[p];
            b[p] = x;
            p = temp;
        }
        else
        {
            break;
        }
    }

    return 0;
}

int main()
{
    int n;
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
    std::cout << "Heap Sort" << std::endl;
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        heap(i, n);
    }
    for (i = 0; i < n; i++)
    {
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
        int temp = b[0];
        b[0] = b[n - 1 - i];
        b[n - 1 - i] = temp;
        heap(0, n - 1 - i);
    }
    int temp = b[0];
    b[0] = b[n - 1 - i];
    b[n - 1 - i] = temp;
    heap(0, n - 1 - i);
    for (int j = 0; j < n - 1; j++)
    {
        std::cout << b[j] << " ";
    }
    std::cout << b[n - 1];
    return 0;
}