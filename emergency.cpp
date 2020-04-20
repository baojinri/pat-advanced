#include <iostream>
const int MAXSIZE = 510;
const int INF = 100000;
struct graph
{
    int cities[MAXSIZE];
    int n;
    int loads[MAXSIZE][MAXSIZE];
};
int dijkstra(graph g, int v, int num[], int weight[]);

int main()
{
    int city_count, path_count, v, u;
    std::cin >> city_count >> path_count >> v >> u;
    graph g;
    g.n = city_count;
    for (int i = 0; i < MAXSIZE; i++)
    {
        g.cities[i]=0;
        for (int j = 0; j < MAXSIZE; j++)
        {
            g.loads[i][j] = INF;
        }
    }

    for (int i = 0; i < city_count; i++)
    {
        std::cin >> g.cities[i];
    }
    for (int i = 0; i < path_count; i++)
    {
        int x, y;
        std::cin >> x >> y;
        std::cin >> g.loads[x][y];
        g.loads[y][x] = g.loads[x][y];
    }
    int num[MAXSIZE];
    int weight[MAXSIZE];
    dijkstra(g, v, num, weight);
    std::cout << num[u] << " " << weight[u] << std::endl;
    system("pause");
    return 0;
}

int dijkstra(graph g, int v, int num[], int weight[])
{
    int dist[MAXSIZE];
    int visited[MAXSIZE];
    for (int i = 0; i < g.n; i++)
    {
        visited[i] = 0;
        num[i] = 0;
        dist[i]=INF;
        weight[i]=0;
    }
    for (int i = 0; i < g.n; i++)
    {
        if (g.loads[v][i] != INF)
            dist[i] = g.loads[v][i], weight[i] = g.cities[v] + g.cities[i], num[i] = 1;
    }
    visited[v] = 1;

    for (int i = 0; i < g.n - 1; i++)
    {
        int min = INF, u ;
        for (int j = 0; j < g.n; j++)
        {
            if (visited[j] == 0 && dist[j] < min)
                min = dist[j], u = j;
        }
        visited[u] = 1;
        for (int j = 0; j < g.n; j++)
        {
            if(visited[j]==0 && g.loads[u][j]!=INF)
            {
                if ( dist[j] > dist[u] + g.loads[u][j])
                dist[j] = dist[u] + g.loads[u][j], weight[j] = g.cities[j] + weight[u], num[j] = num[u];
                else if (dist[j] == dist[u] + g.loads[u][j])
                {
                   if (weight[j] < g.cities[j] + weight[u])
                   {
                    weight[j] = g.cities[j] + weight[u];
                   }
                num[j] = num[j] + num[u];
                }
            }
        }
    }

    return 0;
}



