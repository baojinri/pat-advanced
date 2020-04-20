#include <algorithm>
#include <iostream>
#include <map>
std::map<int, int> s;
int pre[10010], in[10010];
int n, m;

int find(int p, int q, int p1, int p2, int root)
{
    int inp = s[pre[root]] - 1;
    if ((inp - p1) * (inp - p2) < 0)
    {
        std::cout << "LCA of " << in[p1] << " and " << in[p2] << " is "
                  << in[inp] << "." << std::endl;
        return 0;
    }
    if (inp == p1)
    {
        std::cout << in[p1] << " is an ancestor of " << in[p2] << "." << std::endl;
        return 0;
    }
    if (inp == p2)
    {
        std::cout << in[p2] << " is an ancestor of " << in[p1] << "." << std::endl;
        return 0;
    }
    if (p1 < inp && p2 < inp)
    {
        find(p, inp, p1, p2, root + 1);
    }
    else
    {
        find(inp + 1, q, p1, p2, root + inp - p + 1);
    }
    return 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> in[i];
        s[in[i]] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> pre[i];
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        int p1 = s[x] - 1, p2 = s[y] - 1;

        if (p1 == -1 && p2 == -1)
            std::cout << "ERROR: " << x << " and " << y << " are not found." << std::endl;
        else if (p1 == -1 && p2 != -1)
            std::cout << "ERROR: " << x << " is not found." << std::endl;
        else if (p2 == -1 && p1 != -1)
            std::cout << "ERROR: " << y << " is not found." << std::endl;
        else
        {
            find(0, n, p1, p2, 0);
        }
    }

    return 0;
}