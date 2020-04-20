#include <iostream>
int edage[510][510];
int visited[510] = {0};
int n;
int degree[510];

int dfs(int v)
{
    visited[v] = 1;
    int sum = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (edage[v][i] == 1)
            sum++;
    }
    degree[v] = sum;
    for (int i = 1; i < n + 1; i++)
    {
        if (visited[i] == 0 && edage[i][v] == 1)
            dfs(i);
    }
    return 0;
}

int main()
{
    for (int i = 0; i < 510; i++)
    {
        for (int j = 0; j < 510; j++)
        {
            edage[i][j] = 0;
        }
    }
    int m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        edage[x][y] = 1;
        edage[y][x] = 1;
    }
    int sum = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
            sum++;
        }
    }
    for (int i = 0; i < 510; i++)
    {
        visited[i] = 0;
    }
    int odd = 0;
    for (int i = 1; i < n + 1; i++)
    {
        std::cout << degree[i];
        if (degree[i] % 2 == 1)
            odd++;
        if (i != n)
            std::cout << " ";
        else
        {
            std::cout << std::endl;
        }
    }
    if (odd == 0 && sum == 1)
        std::cout << "Eulerian";
    else if (odd == 2 && sum == 1)
        std::cout << "Semi-Eulerian";
    else
        std::cout << "Non-Eulerian";

    return 0;
}