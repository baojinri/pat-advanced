#include <iostream>
int a[50010];
int b[50010];
int n;

/*int build(int p, int q)
{
    if (p + 1 == q)
    {
        std::cout << b[p];
        return 0;
    }
    int temp;
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = p; j < q; j++)
        {
            if (b[j] == a[i])
            {
                temp = j;
                break;
            }
        }
        if (j < q)
            break;
    }
    if (p < temp)
        build(p, temp);
    else
        build(temp + 1, q);
    return 0;
}*/

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> b[i];
    }
    int p = 0, q = n;
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = p; j < q; j++)
        {
            if (b[j] == a[i])
            {
                temp = j;
                break;
            }
        }
        if (temp > p)
            q = temp;
        else if (temp + 1 < q)
            p = temp + 1;
        else
        {
            std::cout << b[temp];
            break;
        }
    }

    return 0;
}