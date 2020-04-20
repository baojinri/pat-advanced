#include <iostream>
int graph[1010][1010];
int visited[1010] = {0};
int n;
int v[1010];
void dfs(int v )
{
    visited[v]=1;
    for (int i = 1; i < n+1; i++)
    {
        if(visited[i]==0 && (graph[i][v]==1 || graph[v][i]==1))
            dfs(i);
    } 
}

int main()
{
    std::ios::sync_with_stdio(false);
    int  m, k;
    std::cin >> n >> m >> k;
    for (int i = 0; i < 1010; i++)
    {
        for (int j = 0; j < 1010; j++)
        {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int temp1, temp2;
        std::cin >> temp1 >> temp2;
        graph[temp1][temp2] = 1;
        graph[temp1][temp2] = 1;
    }
    for (int i = 0; i < k; i++)
    {
        std::cin >> v[i];
    }
    for (int i = 0; i < k; i++)
    {
        int sum = -1;
        visited[v[i]] = 1;
        for (int j = 1; j < n+1; j++)
        {
            if(visited[j]==0)
                dfs(j), sum = sum + 1;
        }
        for (int j = 1; j< n+1; j++)
        {
            visited[j] = 0;
        }
        std::cout << sum << std::endl;
    }
    system("pause");
    return 0;
}