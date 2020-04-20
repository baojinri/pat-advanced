#include <iostream>
int hah[10010] = {0};

bool isprime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int m, n;
    std::cin >> m >> n;
    while (true)
    {
        if (isprime(m))
            break;
        m++;
    }

    for (int i = 0; i < n; i++)
    {
        int position, temp;
        int flag = 0;
        std::cin >> temp;
        for (int j = 0; j < m; j++)
        {
            position = (temp + j * j) % m;
            if (hah[position] == 0)
            {
                std::cout << position;
                hah[position] = 1;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            std::cout << "-";
        if (i < n - 1)
            std::cout << " ";
    }
    return 0;
}