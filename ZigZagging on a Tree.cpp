#include <iostream>
struct node
{
    int date;
    int level;
};
int a[50];
int b[50];
int n;
node c[50];
int count = 0;

int build(int p, int q, int deep)
{
    if (p + 1 == q)
    {
        c[count].date = a[p];
        c[count].level = deep;
        count++;
        return 0;
    }
    int temp;
    for (int i = n - 1; i >= 0; i--)
    {
        int j;
        for (j = p; j < q; j++)
        {
            if (b[i] == a[j])
            {
                temp = j;
                break;
            }
        }
        if (j < q)
            break;
    }
    c[count].date = a[temp];
    c[count].level = deep;
    count++;
    if (p < temp)
    {
        build(p, temp, deep + 1);
    }
    if (q > temp + 1)
    {

        build(temp + 1, q, deep + 1);
    }
    return 0;
}

int main()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> b[i];
    }
    build(0, n, 0);
    for (int i = 0; i < count; i++)
    {
        for (int j = count - 1; j > i; j--)
        {
            if (c[j].level < c[j - 1].level)
            {
                node temp = c[j];
                c[j] = c[j - 1];
                c[j - 1] = temp;
            }
        }
    }
    int p = 0;
    int q;
    int sum = 0;
    c[count].level = c[count - 1].level + 1;
    for (int i = 1; i < count + 1; i++)
    {
        if (c[i].level != c[p].level)
        {
            q = i;
            if (c[p].level % 2 == 0)
            {
                for (int j = q - 1; j >= p; j--)
                {
                    std::cout << c[j].date;
                    sum++;
                    if (sum != n)
                        std::cout << " ";
                    else
                        std::cout << std::endl;
                }
            }
            else
            {
                for (int j = p; j < q; j++)
                {
                    std::cout << c[j].date;
                    sum++;
                    if (sum != n)
                        std::cout << " ";
                    else
                        std::cout << std::endl;
                }
            }
            p = q;
        }
    }
    return 0;
}