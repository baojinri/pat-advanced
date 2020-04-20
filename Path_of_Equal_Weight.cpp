#include<iostream>
#include<algorithm>
#include<cstdio>
struct node
{
    int weight;
    int k=0;
    int id[100];
};
node tree[100];
int path[100];
int s;

bool cmp(int a,int b)
{
    return tree[a].weight > tree[b].weight;
}

int dfs(int v,int deep,int sum)
{
    sum += tree[v].weight;
    path[deep] = v;
    if(tree[v].k==0)
    {
        if(sum==s)
        {
            for (int i = 0; i < deep; i++)
            {
                std::cout<<tree[path[i]].weight << " ";
            }
            std::cout<<tree[path[deep]].weight << std::endl;
        }
        return 0;
    }
    for (int i = 0; i <tree[v].k; i++)
    {
        dfs(tree[v].id[i], deep + 1, sum);
    }
    return 0;
}

int main()
{
    int n, m;
    std::cin >> n >> m >> s;
    for (int i = 0; i < n; i++)
    {
        std::cin >> tree[i].weight;
    }
    for (int i = 0; i < m; i++)
    {
        int temp;
        std::cin >> temp;
        std::cin >> tree[temp].k;
        for (int j = 0; j < tree[temp].k; j++)
        {
            std::cin >> tree[temp].id[j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        std::sort(tree[i].id, tree[i].id + tree[i].k, cmp);
    }
    dfs(0, 0, 0);

    return 0;
}