#include <iostream>
int hash[10010] = {0};

bool isprime(int v)
{
    if (v == 1)
        return false;
    for (int i = 2; i * i <= v; i++)
    {
        if (v % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int m, n, k;
    std::cin >> m >> n >> k;
    while (!isprime(m))
    {
        m++;
    }
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        int position;
        int flag = 0;
        for (int j = 0; j < m; j++)
        {
            position = (temp + j * j) % m;
            if (hash[position] == 0)
            {
                hash[position] = temp;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            std::cout << temp << " cannot be inserted." << std::endl;
    }
    double sum = 0;
    double num = 0;
    for (int i = 0; i < k; i++)
    {
        int temp;
        std::cin >> temp;
        int position;
        int j;
        for (j = 0; j < m; j++)
        {
            position = (temp + j * j) % m;
            if (hash[position] == temp || hash[position] == 0)
            {
                break;
            }
        }
        sum += j + 1;
        num++;
    }
    printf("%0.1f", sum / num);

    return 0;
}