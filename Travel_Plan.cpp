#include <iostream>
struct road
{
    int weight, cost;
};
road edage[510][510];
const int INF = 100000;
int visited[510] = {0};

int show(int path[], int u)
{
    if (path[u] != -1)
        show(path, path[u]);

    std::cout << u << " ";
    return 0;
}

int main()
{
    int n, m, v, u;
    std::cin >> n >> m >> v >> u;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            edage[i][j].weight = INF;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        std::cin >> edage[x][y].weight >> edage[x][y].cost;
        edage[y][x].weight = edage[x][y].weight;
        edage[y][x].cost = edage[x][y].cost;
    }
    int dist[510], cost[510], path[510];
    for (int i = 0; i < n; i++)
    {
        if (edage[v][i].weight < INF)
        {
            dist[i] = edage[v][i].weight;
            cost[i] = edage[v][i].cost;
            path[i] = v;
        }
        else
        {
            dist[i] = INF;
            path[i] = -1;
        }
    }
    path[v] = -1;
    visited[v] = 1;
    for (int i = 1; i < n; i++)
    {
        int d = -1, min = INF;
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                d = j;
            }
        }
        if (d == -1)
            break;
        visited[d] = 1;
        for (int j = 0; j < n; j++)
        {
            if (edage[d][j].weight < INF && visited[j] == 0)
            {
                if (dist[j] > dist[d] + edage[d][j].weight)
                {
                    dist[j] = dist[d] + edage[d][j].weight;
                    cost[j] = cost[d] + edage[d][j].cost;
                    path[j] = d;
                }
                else if (dist[j] == dist[d] + edage[d][j].weight && cost[j] > cost[d] + edage[d][j].cost)
                {
                    cost[j] = cost[d] + edage[d][j].cost;
                    path[j] = d;
                }
            }
        }
    }
    show(path, u);
    std::cout << dist[u] << " " << cost[u];
    return 0;
}