#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
struct node
{
    std::vector<int> child;
};
node tree[100010];
int min = 100000;
int count = 0;

int dfs(int v, int deep)
{
    if (tree[v].child.size() == 0)
    {
        if (min > deep)
        {
            min = deep;
            count = 1;
        }
        else if (min == deep)
            count++;
        return 0;
    }
    for (int i = 0; i < tree[v].child.size(); i++)
    {
        dfs(tree[v].child[i], deep + 1);
    }
    return 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    double p, r;
    std::cin >> n >> p >> r;
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        if (temp != 0)
        {
            for (int j = 0; j < temp; j++)
            {
                int a;
                std::cin >> a;
                tree[i].child.push_back(a);
            }
        }
    }
    dfs(0, 0);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(4) << p * pow(1 + r / 100, min) << " " << count;
    return 0;
}