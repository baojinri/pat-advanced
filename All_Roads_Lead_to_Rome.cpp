#include <iostream>
#include <string>
struct city
{
    std::string name;
    int weight;
} city[210];
int edage[210][210];
const int INF = 10000000;
int path[210];

int show(int v)
{
    if (path[v] == -1)
    {
        std::cout << city[v].name << "->";
        return 0;
    }
    show(path[v]);
    std::cout << city[v].name << "->";
    return 0;
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::cin >> city[0].name;
    for (int i = 1; i < n; i++)
    {
        std::cin >> city[i].name >> city[i].weight;
    }
    for (int i = 0; i < 210; i++)
    {
        for (int j = 0; j < 210; j++)
        {
            edage[i][j] = INF;
        }
    }

    for (int i = 0; i < k; i++)
    {
        std::string str1, str2;
        std::cin >> str1 >> str2;
        int flag1, flag2;
        for (int i = 0; i < n; i++)
        {
            if (city[i].name == str1)
                flag1 = i;
            if (city[i].name == str2)
                flag2 = i;
        }
        std::cin >> edage[flag1][flag2];
        edage[flag2][flag1] = edage[flag1][flag2];
    }
    int visited[210] = {0}; //标记访问
    int dist[210];          //标记距离
    int number[210] = {0};  //标记城市数
    int weight[210] = {0};  //幸福值
    int num[210];           //路径数
    path[0] = -1;
    for (int i = 1; i < n; i++)
    {
        if (edage[0][i] != INF)
        {
            dist[i] = edage[0][i];
            path[i] = 0;
        }
        else
        {
            dist[i] = INF;
            path[i] = -1;
        }
        number[i] = 1;
        weight[i] = city[i].weight;
        num[i] = 1;
    }
    visited[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int min = INF, v = -1;
        for (int j = 0; j < n; j++)
        {
            if (dist[j] < min && visited[j] == 0)
            {
                min = dist[j];
                v = j;
            }
        }
        visited[v] = 1;
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == 0)
            {
                if (dist[j] > dist[v] + edage[j][v])
                {
                    dist[j] = dist[v] + edage[j][v];
                    path[j] = v;
                    number[j] = number[v] + 1;
                    weight[j] = weight[v] + city[j].weight;
                    num[j] = num[v];
                }
                else if (dist[j] == dist[v] + edage[j][v])
                {
                    if (weight[j] < weight[v] + city[j].weight)
                    {
                        path[j] = v;
                        number[j] = number[v] + 1;
                        weight[j] = weight[v] + city[j].weight;
                    }
                    else if (weight[j] == weight[v] + city[j].weight)
                    {
                        if (weight[j] / number[j] < (weight[v] + city[j].weight) / (number[v] + 1))
                        {
                            path[j] = v;
                            number[j] = number[v] + 1;
                        }
                    }
                    num[j] += num[v];
                }
            }
        }
    }
    int i;
    for (i = 0; i < n; i++)
    {
        if (city[i].name == "ROM")
            break;
    }
    std::cout << num[i] << " " << dist[i] << " " << weight[i] << " " << weight[i] / number[i] << std::endl;
    show(path[i]);
    std::cout << "ROM";
    return 0;
}