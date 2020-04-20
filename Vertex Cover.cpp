#include <iostream>
#include <vector>
std::vector<int> edage[10010];

int main()
{
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        edage[x].push_back(i);
        edage[y].push_back(i);
    }
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++)
    {
        int temp;
        int visited[10010] = {0};
        std::cin >> temp;
        for (int j = 0; j < temp; j++)
        {
            int x;
            std::cin >> x;
            for (int p = 0; p < edage[x].size(); p++)
            {
                visited[edage[x][p]] = 1;
            }
        }
        int j;
        for (j = 0; j < m; j++)
        {
            if (visited[j] == 0)
                break;
        }
        if (j < m)
            std::cout << "No" << std::endl;
        else
            std::cout << "Yes" << std::endl;
    }

    return 0;
}