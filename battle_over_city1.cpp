#include <iostream>
#include<stdio.h>
struct arcnode
{
    int date;
    struct arcnode *next;
};
struct handnode
{
    int date;
    struct arcnode *firstarc;
};
struct graph
{
    handnode cities[1000];
};

int visited[1000] = {0};
int v[1000];

void dfs(graph *g, int v)
{
    visited[v] = 1;
    arcnode *q = g->cities[v].firstarc;
    while (q != NULL)
    {
        if (visited[q->date] ==0)
            dfs(g, q->date);
        q = q->next;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    graph *g=new graph;
    for (int i = 1; i < n + 1; i++)
    {
        g->cities[i].date = i;
        g->cities[i].firstarc = NULL;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        arcnode *p = new arcnode;
        p->date = b;
        p->next = g->cities[a].firstarc;
        g->cities[a].firstarc = p;
        delete p;

        arcnode *q = new arcnode;
        q->date = a;
        q->next = g->cities[b].firstarc;
        g->cities[b].firstarc = q;
        delete q;
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < k; i++)
    {
        int sum = -1;
        for (int j = 1; j < n + 1; j++)
        {
            visited[v[i]] = 1;
            if (visited[j] == 0 )
                dfs(g, j), sum = sum + 1;
        }
        std::cout << sum << std::endl;
        for (int i = 1; i < n+1; i++)
        {
            visited[i] = 0;
        }
        sum = -1;
    }
    delete g;
    system("pause");
    return 0;
}