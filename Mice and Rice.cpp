#include <algorithm>
#include <iostream>
int temp[1010];
struct node
{
    int weight, order, rank = -1;
} a[1010];
node s[1010];

bool cmp(node a, node b)
{
    return a.order < b.order;
}

bool cmp2(node a, node b)
{
    return a.weight > b.weight;
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        std::cin >> temp[i];
    }
    for (int i = 0; i < n; i++)
    {
        int order;
        std::cin >> order;
        a[i].weight = temp[order];
        a[i].order = order;
    }
    while (k > n)
    {
        int count = 0;
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i].rank == -1)
                s[count++] = a[i];
            if (count == k)
            {
                std::sort(s, s + count, cmp2);
                s[0].rank = 0;
                num++;
                count = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i].rank == -1)
                a[i].rank = num + 1;
            if (a[i].rank == 0)
                a[i].rank = -1;
        }
        k = k * k;
    }
    std::sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i].rank;
        if (i != n - 1)
            std::cout << " ";
    }

    return 0;
}