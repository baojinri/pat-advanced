#include <iostream>
int edage[1010][1010] = {{0}};
int edage2[1010][1010] = {{0}};
int sum[1010];
int count = 0;

int main()
{
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        edage[x][y] = 1;
    }
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            for (int p = 1; p < n + 1; p++)
            {
                edage2[j][p] = edage[j][p];
            }
        }

        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            int temp;
            std::cin >> temp;
            if (flag == 0)
            {
                for (int p = 1; p < n + 1; p++)
                {
                    if (edage2[p][temp] == 1)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    for (int p = 1; p < n + 1; p++)
                    {
                        edage2[temp][p] = 0;
                    }
                }
            }
        }
        if (flag == 1)
            sum[count++] = i;
    }
    for (int i = 0; i < count; i++)
    {
        std::cout << sum[i];
        if (i != count - 1)
            std::cout << " ";
    }
    return 0;
}