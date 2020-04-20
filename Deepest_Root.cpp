#include <iostream>
struct arcnode
{
    int date;
    arcnode *next;
};
struct hnode
{
    arcnode *firstarc;
};
hnode g[10010];
int visited[10010] = {0};
int temp = 0;

int dfs(int v)
{
    visited[v] = 1;
    arcnode *p = g[v].firstarc;
    while (p != NULL)
    {
        if (visited[p->date] == 0)
            dfs(p->date);
        p = p->next;
    }
    return 0;
}

int dfs(int v, int deep)
{
    visited[v] = 1;
    if (deep > temp)
    {
        temp = deep;
    }
    arcnode *p = g[v].firstarc;
    while (p != NULL)
    {
        if (visited[p->date] == 0)
            dfs(p->date, deep + 1);
        p = p->next;
    }
    return 0;
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        arcnode *p = new arcnode;
        p->date = y;
        p->next = g[x].firstarc;
        g[x].firstarc = p;

        arcnode *q = new arcnode;
        q->date = x;
        q->next = g[y].firstarc;
        g[y].firstarc = q;
    }
    int sum = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (visited[i] == 0)
        {
            sum++;
            dfs(i);
        }
    }
    if (sum > 1)
    {
        std::cout << "Error: " << sum << " components" << std::endl;
    }
    else
    {
        int deepest = 0;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                visited[j] = 0;
            }
            dfs(i, 0);
            if (deepest < temp)
            {
                deepest = temp;
            }
            temp = 0;
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                visited[j] = 0;
            }
            dfs(i, 0);
            if (temp == deepest)
            {
                std::cout << i << std::endl;
            }
            temp = 0;
        }
    }

    return 0;
}
