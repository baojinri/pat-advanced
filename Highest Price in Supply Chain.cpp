#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
struct node
{
    std::vector<int> child;
};
node tree[100010];
int max = 0;
int count = 0;

int dfs(int v, int deep)
{
    if (tree[v].child.size() == 0)
    {
        if (max < deep)
        {
            max = deep;
            count = 1;
        }
        else if (max == deep)
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
    int flag;
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        if (temp == -1)
        {
            flag = i;
        }
        else
        {
            tree[temp].child.push_back(i);
        }
    }
    dfs(flag, 0);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << p * pow(1 + r / 100, max) << " " << count;
    return 0;
}