#include <algorithm>
#include <cstdio>
#include <iostream>
struct node
{
    int adress, date, next;
};
node l[100000];
int visited[100000] = {0};
int flag[100000];
int count = 0;

int main()
{
    int adress, n;
    std::cin >> adress >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        std::cin >> l[temp].date >> l[temp].next;
        l[temp].adress = temp;
    }
    int p = adress;
    while (p != -1)
    {
        if (p == adress)
        {
            printf("%05d", l[p].adress);
            std::cout << " " << l[p].date << " ";
            visited[std::abs(l[p].date)] = 1;
        }
        else
        {
            if (visited[std::abs(l[p].date)] == 0)
            {
                printf("%05d", l[p].adress);
                std::cout << std::endl;
                printf("%05d", l[p].adress);
                std::cout << " " << l[p].date << " ";
                visited[std::abs(l[p].date)] = 1;
            }
            else
            {
                flag[count++] = p;
            }
        }
        p = l[p].next;
    }
    std::cout << -1 << std::endl;
    if (count != 0)
    {
        printf("%05d", l[flag[0]].adress);
        std::cout << " " << l[flag[0]].date << " ";
        for (int i = 1; i < count; i++)
        {
            printf("%05d", l[flag[i]].adress);
            std::cout << std::endl;
            printf("%05d", l[flag[i]].adress);
            std::cout << " " << l[flag[i]].date << " ";
        }
        std::cout << -1 << std::endl;
    }
    return 0;
}
