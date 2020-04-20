#include <iostream>
struct node
{
    int rank = 0;
    int flag;
};
node s[10010];

bool isprime(int v)
{
    for (int i = 2; i < v; i++)
    {
        if (v % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        s[temp].rank = i + 1;
    }
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++)
    {
        int temp;
        std::cin >> temp;
        if (s[temp].rank == 0)
        {
            printf("%04d", temp);
            std::cout << ": Are you kidding?" << std::endl;
        }
        else if (s[temp].flag == 1)
        {
            printf("%04d", temp);
            std::cout << ": Checked" << std::endl;
        }
        else if (s[temp].rank == 1)
        {
            printf("%04d", temp);
            std::cout << ": Mystery Award" << std::endl;
            s[temp].flag = 1;
        }
        else
        {
            if (isprime(s[temp].rank))
            {
                printf("%04d", temp);
                std::cout << ": Minion" << std::endl;
            }
            else
            {
                printf("%04d", temp);
                std::cout << ": Chocolate" << std::endl;
            }
            s[temp].flag = 1;
        }
    }

    return 0;
}