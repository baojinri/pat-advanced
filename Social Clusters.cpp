#include <algorithm>
#include <iostream>
#include <string>
int father[1010];
int num[1010] = {0};
int visited[1010] = {0};

int findfather(int v)
{
    int x = v;
    while (father[v] != v)
    {
        v = father[v];
    }
    while (father[x]!=v)
    {
        int z = father[x];
        father[x] = v;
        x = z;
    }
    
    return v;
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
    for (int i = 0; i < 1010; i++)
    {
        father[i] = i;
    }
    int n;
    std::cin >> n;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int temp, x;
        scanf("%d: %d", &temp, &x);
        visited[x] = 1;
        num[findfather(x)]++;
        if (max < x)
            max = x;
        for (int j = 1; j < temp; j++)
        {
            int y;
            std::cin >> y;
            visited[y] = 1;
            if (max < y)
                max = y;
            num[findfather(x)] += num[findfather(y)];
            Union(x, y);
        }
    }
    int count = 0;
    int number[1010];
    for (int i = 1; i < max + 1; i++)
    {
        if (visited[i] == 1 && father[i] == i)
        {
            number[count] = num[i];
            count++;
        }
    }
    std::sort(number, number + count);
    std::cout << count << std::endl;
    for (int i = count - 1; i > -1; i--)
    {
        std::cout << number[i];
        if (i != 0)
            std::cout << " ";
    }

    return 0;
}