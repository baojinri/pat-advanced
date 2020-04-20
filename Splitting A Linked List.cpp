#include <iostream>
struct node
{
    int adress;
    int date;
    int next;
};
node list[100000];

int main()
{
    int adress, n, k;
    std::cin >> adress >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        std::cin >> list[temp].date >> list[temp].next;
        list[temp].adress = temp;
    }
    int p = adress;
    int sum = 0;
    while (p != -1)
    {
        if (list[p].date < 0)
        {
            sum++;
            if (sum == 1)
            {
                printf("%05d", p);
                std::cout << " " << list[p].date << " ";
            }
            else
            {
                printf("%05d", p);
                std::cout << std::endl;
                printf("%05d", p);
                std::cout << " " << list[p].date << " ";
            }
        }
        p = list[p].next;
    }
    p = adress;
    while (p != -1)
    {
        if (list[p].date >= 0 && list[p].date <= k)
        {
            sum++;
            if (sum == 1)
            {
                printf("%05d", p);
                std::cout << " " << list[p].date << " ";
            }
            else
            {
                printf("%05d", p);
                std::cout << std::endl;
                printf("%05d", p);
                std::cout << " " << list[p].date << " ";
            }
        }
        p = list[p].next;
    }
    p = adress;
    while (p != -1)
    {
        if (list[p].date > k)
        {
            sum++;
            if (sum == 1)
            {
                printf("%05d", p);
                std::cout << " " << list[p].date << " ";
            }
            else
            {
                printf("%05d", p);
                std::cout << std::endl;
                printf("%05d", p);
                std::cout << " " << list[p].date << " ";
            }
        }
        p = list[p].next;
    }
    std::cout << -1;
    return 0;
}