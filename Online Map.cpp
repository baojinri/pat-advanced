#include <iostream>
const int INF = 100000;
struct node
{
    int length = INF;
    int time = INF;
};
node edage[510][510];

int show(int a[], int v)
{
    if (a[v] != -1)
        show(a, a[v]);
    std::cout << v << " -> ";
    return 0;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2, tag;
        std::cin >> v1 >> v2 >> tag;
        std::cin >> edage[v1][v2].length >> edage[v1][v2].time;
        if (tag == 0)
            edage[v2][v1] = edage[v1][v2];
    }
    int v1, v2;
    std::cin >> v1 >> v2;
    int dist[510], tdist[510], path[510], tpath[510];
    int visited[510] = {0};
    int time[510], number[510];
    for (int i = 0; i < n; i++)
    {
        if (edage[v1][i].length != INF)
        {
            dist[i] = edage[v1][i].length;
            path[i] = v1;
            time[i] = edage[v1][i].time;
        }
        else
        {
            dist[i] = INF;
            path[i] = -1;
            time[i] = INF;
        }
    }
    visited[v1] = 1;
    for (int i = 1; i < n; i++)
    {
        int min = INF, v;
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                v = j;
            }
        }
        visited[v] = 1;
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == 0 && dist[j] > dist[v] + edage[v][j].length)
            {
                dist[j] = dist[v] + edage[v][j].length;
                path[j] = v;
                time[j] = time[v] + edage[v][j].time;
            }
            else if (visited[j] == 0 && dist[j] == dist[v] + edage[v][j].length)
            {
                if (time[j] > time[v] + edage[v][j].time)
                {
                    path[j] = v;
                    time[j] = time[v] + edage[v][j].time;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (edage[v1][i].time != INF)
        {
            tdist[i] = edage[v1][i].time;
            tpath[i] = v1;
            number[i] = 1;
        }
        else
        {
            tdist[i] = INF;
            tpath[i] = -1;
            number[i] = 0;
        }
    }
    visited[v1] = 1;
    for (int i = 1; i < n; i++)
    {
        int min = INF, v;
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == 0 && tdist[j] < min)
            {
                min = tdist[j];
                v = j;
            }
        }
        visited[v] = 1;
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == 0 && tdist[j] > tdist[v] + edage[v][j].time)
            {
                tdist[j] = tdist[v] + edage[v][j].time;
                tpath[j] = v;
                number[j] = number[v] + 1;
            }
            else if (visited[j] == 0 && tdist[j] == tdist[v] + edage[v][j].time)
            {
                if (number[j] > number[v] + 1)
                {
                    tpath[j] = v;
                    number[j] = number[v] + 1;
                }
            }
        }
    }
    int p = v2;
    while (path[p] == tpath[p] && p != -1)
    {
        p = path[p];
    }
    if (p == -1)
    {
        std::cout << "Distance = " << dist[v2] << "; Time = " << tdist[v2] << ": ";
        show(path, path[v2]);
        std::cout << v2;
    }
    else
    {
        std::cout << "Distance = " << dist[v2] << ": ";
        show(path, path[v2]);
        std::cout << v2 << std::endl;
        std::cout << "Time = " << tdist[v2] << ": ";
        show(tpath, tpath[v2]);
        std::cout << v2 << std::endl;
    }

    return 0;
}