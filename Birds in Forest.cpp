#include <iostream>
int father[10010];
int max = -1;

int findfather(int x)
{
    int a = x;
    while (father[x] != x)
    {
        x = father[x];
    }
    while (a != father[a])
    {
        int z = a;
        a = father[a];
        father[z] = x;
    }

    return x;
}

int Union(int a, int b)
{
    int x = findfather(a);
    int y = findfather(b);
    if (x != y)
        father[y] = x;
    return 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    for (int i = 0; i < 10010; i++)
    {
        father[i] = i;
    }
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        std::cin >> k;
        int temp;
        std::cin >> temp;
        if (temp > max)
            max = temp;
        for (int j = 1; j < k; j++)
        {
            int a;
            std::cin >> a;
            if (max < a)
                max = a;
            Union(temp, a);
        }
    }
    int count = 0;
    for (int i = 1; i < max + 1; i++)
    {
        if (father[i] == i)
            count++;
    }
    std::cout << count << " " << max << std::endl;
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        std::cin >> x >> y;
        if (findfather(x) == findfather(y))
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
    }

    return 0;
}