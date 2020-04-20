#include <iostream>

int edage[1010][1010];
int n, l;
int visited[1010] = {0};
int count = 0;
int quuene[1010];
int f = 0, r = 0;

int bfs(int v)
{
    quuene[r++] = v;
    visited[v] = 1;
    int deep[1010] = {0};
    while (r != f)
    {
        int temp = quuene[f++];
        for (int i = 1; i < n + 1; i++)
        {
            if (visited[i] == 0 && edage[temp][i] == 1 && deep[temp] < l)
            {
                quuene[r++] = i;
                deep[i] = deep[temp] + 1;
                visited[i] = 1;
                count++;
            }
        }
    }
    return 0;
}

int main()
{
    std::cin >> n >> l;
    for (int i = 0; i < 1010; i++)
    {
        for (int j = 0; j < 1010; j++)
        {
            edage[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int k;
        std::cin >> k;
        for (int j = 0; j < k; j++)
        {
            int temp;
            std::cin >> temp;
            edage[temp][i + 1] = 1;
        }
    }
    int m;
    std::cin >> m;
    int a[1010];
    for (int i = 0; i < m; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        bfs(a[i]);
        std::cout << count << std::endl;
        count = 0;
        f = 0;
        r = 0;
        for (int j = 0; j < 1010; j++)
        {
            visited[j] = 0;
            quuene[j] = 0;
        }
    }

    return 0;
}