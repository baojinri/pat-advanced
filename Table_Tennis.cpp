#include <iostream>
#include <string>
struct play
{
    std::string arr;
    int service;
    int vip;
    std::string fin;
};
play cust[10010];
struct table
{
    std::string begin, finish;
    int vip;
};
table w[110];

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> cust[i].arr >> cust[i].service >> cust[i].vip;
    }
    int k, m;
    std::cin >> k >> m;
    for (int i = 1; i < k + 1; i++)
    {
        w[i].begin = "08:00:00";
        w[i].vip = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        std::cin >> x;
        w[x].vip = 1;
    }
    play temp;
    for (int i = 0; i < n; i++)     //sort
    {
        for (int j = n - 1; j > i; j--)
        {
            if (cust[j].arr < cust[j - 1].arr)
            {
                temp = cust[j];
                cust[j] = cust[j - 1];
                cust[j - 1] = temp;
            }
        }
    }

    if(k>=n)
    {
        for (int i = 0; i < n; i++)
        {
            cust[i].fin = cust[i].arr;
        }
        
    }

    return 0;
}