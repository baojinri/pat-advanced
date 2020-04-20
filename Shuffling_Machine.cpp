#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int a[55];
    int p[55];
    for (int i = 1; i < 55; i++)
    {
        std::cin >> a[i];
        p[i] = i-1;
    }
    int temp[55];
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < 55; j++)
        {
            temp[a[j]] = p[j];
        }
        for (int j = 1; j < 55; j++)
        {
            p[j] = temp[j];
        }
    }
    for (int i = 1; i < 54; i++)
    {
        int x = p[i] % 13;
        int y = p[i] / 13;
        switch (y)
        {
        case 0:
            std::cout << "S";
            break;
        case 1:
            std::cout << "H";
            break;
        case 2:
            std::cout << "C";
            break;
        case 3:
            std::cout << "D";
            break;
        case 4:
            std::cout << "J";
            break;
        }
        std::cout << x+1 << " ";
    }
    int x = p[54] % 13;
    int y = p[54] / 13;
    switch (y)
    {
    case 0:
        std::cout << "S";
        break;
    case 1:
        std::cout << "H";
        break;
    case 2:
        std::cout << "C";
        break;
    case 3:
        std::cout << "D";
        break;
    case 4:
        std::cout << "J";
        break;
    }
    std::cout << x+1;

    return 0;
}