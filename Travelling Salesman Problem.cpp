#include <iostream>
const int INF = 1000000;
int edage[210][210];
int visited[210] = {0};
int a[210];

int main()
{
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < 210; i++)
    {
        for (int j = 0; j < 210; j++)
        {
            edage[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        std::cin >> edage[x][y];
        edage[y][x] = edage[x][y];
    }
    int k;
    std::cin >> k;
    int v = 0;
    int min = INF;
    for (int i = 0; i < k; i++)
    {
        int temp;
        int sum = 0;
        std::cin >> temp;
        for (int j = 0; j < temp; j++)
        {
            std::cin >> a[j];
        }
        for (int j = 1; j < temp; j++)
        {
            sum += edage[a[j - 1]][a[j]];
            visited[a[j]] = 1;
        }
        int j;
        for (j = 1; j < n + 1; j++)
        {
            if (visited[j] == 0)
                break;
        }
        if (temp == n + 1 && a[0] == a[temp - 1] && sum < INF && j == n + 1)
        {
            std::cout << "Path " << i + 1 << ": " << sum << " (TS simple cycle)" << std::endl;
            if (sum < min)
            {
                v = i + 1;
                min = sum;
            }
        }
        else if (j == n + 1 && sum < INF && a[0] == a[temp - 1] && temp > n + 1)
        {
            std::cout << "Path " << i + 1 << ": " << sum << " (TS cycle)" << std::endl;
            if (sum < min)
            {
                v = i + 1;
                min = sum;
            }
        }
        else
        {
            if (sum < INF)
                std::cout << "Path " << i + 1 << ": " << sum << " (Not a TS cycle)" << std::endl;
            else
                std::cout << "Path " << i + 1 << ": "
                          << "NA"
                          << " (Not a TS cycle)" << std::endl;
        }
        for (int j = 0; j < 210; j++)
        {
            visited[j] = 0;
        }
    }
    std::cout << "Shortest Dist(" << v << ") = " << min << std::endl;
    return 0;
}