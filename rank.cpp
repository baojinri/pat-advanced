#include <iostream>
#include <string>
struct grade
{
    std::string name;
    int c, m, e, a;
    int tag;
};
grade g[2000];
int c[2000], math[2000], e[2000], a[2000];
std::string str[2000];

int main()
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        std::cin >> g[i].name >> g[i].c >> g[i].m >> g[i].e;
        g[i].a = (g[i].c + g[i].m + g[i].e) / 3;
        g[i].tag = 0;
    }

    int rank = 1;
    for (int i = 100; i > -1; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[j].c == i)
                g[j].tag = 1;
        }
        int k = 0;
        for (int j = 0; j < n; j++)
        {
            if (g[j].tag == 1)
            {
                g[j].tag = 0;
                k++;
                c[j] = rank;
            }
        }
        rank = rank + k;
        k = 0;
    }

    rank = 1;
    for (int i = 100; i > -1; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[j].m == i)
                g[j].tag = 1;
        }
        int k = 0;
        for (int j = 0; j < n; j++)
        {
            if (g[j].tag == 1)
            {
                g[j].tag = 0;
                k++;
                math[j] = rank;
            }
        }
        rank = rank + k;
        k = 0;
    }

    rank = 1;
    for (int i = 100; i > -1; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[j].e == i)
                g[j].tag = 1;
        }
        int k = 0;
        for (int j = 0; j < n; j++)
        {
            if (g[j].tag == 1)
            {
                g[j].tag = 0;
                k++;
                e[j] = rank;
            }
        }
        rank = rank + k;
        k = 0;
    }

    rank = 1;
    for (int i = 100; i >-1; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if(g[j].a==i)
                g[j].tag = 1;
        }
        int k = 0;
        for (int j = 0; j < n; j++)
        {
            if(g[j].tag==1)
                {
                    g[j].tag = 0;
                    k++;
                    a[j] = rank;
                }    
        }
        rank = rank + k;
        k = 0;
    }

    for (int i = 0; i < m; i++)
    {
        std::cin >> str[i];
    }

    for (int i = 0; i < m; i++)
    {
        int j;
        for (j = 0; j < n; j++)
        {
            if (g[j].name == str[i])
                break;
        }
        if (j == n)
            std::cout << "N/A" << std::endl;
        else
        {
            if (e[j] < math[j] && e[j] < c[j] && e[j] < a[j])
                std::cout << e[j] << " " << 'E' << std::endl;
            else if (math[j] < c[j] && math[j] < a[j])
                std::cout << math[j] << " " << 'M' << std::endl;
            else if (c[j] < a[j])
                std::cout << c[j] << " " << 'C' << std::endl;
            else
                std::cout << a[j] << " " << 'A' << std::endl;
        }
    }
    system("pause");
    return 0;
}