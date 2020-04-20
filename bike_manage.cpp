#include <iostream>
struct graph
{
    int cities[510];
    int edage[510][510];
};
const int INF = 1000000;
int visited[510] = {0};
int temppath[510] = {-1};
int load[510] = {-1};
int cmax, s;
graph g;
int minsend = INF, minback = INF;

int dfs(int path[][510], int v)
{
    for (int i = 0; path[v][i] != -1; i++)
    {
        temppath[v] = path[v][i];
        dfs(path, path[v][i]);
    }
    if (v == 0)
    {
        int send = 0, back = 0;
        int u = s;
        while (temppath[u] != -1)
        {
            if (g.cities[u] < (cmax / 2))
            {
                send += (cmax / 2 - g.cities[u]);
            }
            if (g.cities[u] > (cmax / 2))
            {
                if ((g.cities[u] - cmax / 2) > send)
                    back += (g.cities[u] - cmax / 2) - send, send = 0;
                else
                    send = send - (g.cities[u] - cmax / 2);
            }
            u = temppath[u];
        }
        if (minsend > send)
        {
            minsend = send;
            minback = back;
            for (int i = 0; i < 510; i++)
            {
                load[i] = temppath[i];
            }
        }
        else if (minsend == send && minback > back)
        {
            minsend = send;
            minback = back;
            for (int i = 0; i < 510; i++)
            {
                load[i] = temppath[i];
            }
        }
    }
    return 0;
}

int show(int load[], int s)
{
    if (s == -1)
        return 0;
    else
    {
        show(load, load[s]);
        std::cout << s << "->";
        return 0;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> cmax >> n >> s >> m;

    g.cities[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        std::cin >> g.cities[i];
    }
    for (int i = 0; i < 510; i++)
    {
        for (int j = 0; j < 510; j++)
        {
            g.edage[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int p, q;
        std::cin >> p >> q;
        std::cin >> g.edage[p][q];
        g.edage[q][p] = g.edage[p][q];
    }
    int dist[510];
    int path[510][510];
    for (int i = 0; i < 510; i++)
    {
        for (int j = 0; j < 510; j++)
        {
            path[i][j] = -1;
        }
    }
    int v = 0;
    for (int i = 0; i < n + 1; i++)
    {
        if (g.edage[v][i] != INF)
        {
            dist[i] = g.edage[v][i];
            path[i][0] = v;
        }
        else
        {
            dist[i] = INF;
        }
    }
    visited[v] = 1;
    for (int i = 0; i < n; i++)
    {
        int min = INF;
        int k = -1;
        for (int j = 0; j < n + 1; j++)
        {
            if (visited[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                k = j;
            }
        }
        if (k == -1)
            break;
        visited[k] = 1;
        for (int j = 0; j < n + 1; j++)
        {
            if (visited[j] == 0 && dist[j] > dist[k] + g.edage[j][k])
            {
                dist[j] = dist[k] + g.edage[j][k];
                path[j][0] = k;
                for (int m = 1; m < n + 1; m++)
                {
                    path[j][m] = -1;
                }
            }
            if (visited[j] == 0 && dist[j] == dist[k] + g.edage[j][k])
            {
                int m;
                for (m = 0; m < n + 1; m++)
                {
                    if (path[j][m] == -1)
                        break;
                }
                path[j][m] = k;
            }
        }
    }
    dfs(path, s);
    std::cout << minsend << " ";
    show(load, load[s]);
    std::cout << s << " " << minback;

    return 0;
}