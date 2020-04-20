#include<iostream>
const int MAXSIZE = 10;
const int INF = 10000;
struct  gragh
{
    int edge[MAXSIZE][MAXSIZE];
    int n;
};
int dijkstra(gragh g, int v, int dis[], int path[]);
int show_dist(int path[], int i);

int main()
{
    gragh g;
    g.n = 7;
    for (int i = 0; i < MAXSIZE; i++)
       for (int j = 0; j < MAXSIZE; j++)
             g.edge[i][j] = INF;
    g.edge[0][1] = 4, g.edge[0][2] = 6, g.edge[0][3] = 6;
    g.edge[1][2] = 1, g.edge[1][4] = 7;
    g.edge[2][4] = 6, g.edge[2][5] = 4;
    g.edge[3][2] = 2, g.edge[3][5] = 5;
    g.edge[4][6] = 6;
    g.edge[5][4] = 1, g.edge[5][6] = 8;
    int dist[7];
    int path[7];
    dijkstra(g, 0, dist, path);
    for (int i = 1; i < 7; i++)
    {
        std::cout << i << " min dist is: ";
        std::cout << dist[i] << std::endl;
        std::cout << "dist is: ";
        show_dist(path, i);
        std::cout << std::endl;
    }
    system("pause");
    return 0;
}

int dijkstra(gragh g,int v,int dis[],int path[])
{
    int visited[g.n]={0};
    for (int i = 0; i < g.n; i++)
    {
       if(g.edge[v][i]<INF)
           dis[i] = g.edge[v][i], path[i] = v;
        else
            dis[i] = INF, path[i] = -1;
    }
    visited[v] = 1, path[v] = -1;
    for (int i = 0; i < g.n; i++)
       {
           int min = INF;
           int u;
           for (int j = 0; j < g.n; j++)
           {
               if(visited[j]==0 && dis[j]<min)
                   min = dis[j], u = j;
           }
           visited[u] = 1;
           for (int j = 0; j < g.n; j++)
           {
               if(visited[j]==0 && dis[j]>dis[u]+g.edge[u][j])
                   dis[j] = dis[u] + g.edge[u][j], path[j] = u;
           }  
       }
    return 0;
}
int show_dist(int path[],int i)
{
    if(path[i]!=-1)
        show_dist(path, path[i]);
    std::cout << i << "->";
    return 0;
}