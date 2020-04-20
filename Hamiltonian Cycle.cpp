#include <iostream>
int edage[210][210];
int visited[210] = {0};
int a[210];

int main()
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < 210; i++)
    {
        for (int j = 0; j < 210; j++)
        {
            edage[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        edage[x][y] = 1;
        edage[y][x] = 1;
    }
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++)
    {
        int temp;
        std::cin >> temp;
        for (int j = 0; j < temp; j++)
        {
            std::cin >> a[j];
        }
        if (temp == n + 1 && a[0] == a[temp - 1])
        {
            int p = a[0];
            int j;
            for (j = 1; j < temp; j++)
            {
                if (visited[a[j]] == 0 && edage[p][a[j]] == 1)
                {
                    p = a[j];
                    visited[p] = 1;
                }
                else
                {
                    break;
                }
            }
            if (j == temp)
            {
                std::cout << "YES" << std::endl;
            }
            else
            {
                std::cout << "NO" << std::endl;
            }
        }
        else
        {
            std::cout << "NO" << std::endl;
        }
        for (int j = 0; j < 210; j++)
        {
            visited[j] = 0;
        }
    }
    return 0;
}