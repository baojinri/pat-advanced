#include <iostream>
int edage[210][210] = {{0}};
int a[210];
int count = 0;

int main()
{
    int n, m;
    std::cin >> n >> m;
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
        int flag = 0;
        count = 0;
        std::cin >> temp;
        std::cin >> a[count++];
        for (int j = 1; j < temp; j++)
        {
            std::cin >> a[count];
            for (int p = 0; p < count; p++)
            {
                if (edage[a[count]][a[p]] != 1)
                    flag = 1;
            }
            count++;
        }
        if (flag == 1)
            std::cout << "Not a Clique" << std::endl;
        else
        {
            int j;
            for (j = 1; j < n + 1; j++)
            {
                int p;
                for (p = 0; p < count; p++)
                {
                    if (j == a[p] || edage[j][a[p]] == 0)
                        break;
                }
                if (p == count)
                    break;
            }
            if (j < n + 1)
                std::cout << "Not Maximal" << std::endl;
            else
            {
                std::cout << "Yes" << std::endl;
            }
        }
    }

    return 0;
}