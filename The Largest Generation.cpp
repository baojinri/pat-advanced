#include <iostream>
#include <vector>
struct node
{
    int k;
    std::vector<int> child;
};
node tree[110];
int number[110] = {0};
int deep[110] = {0};
int quene[110];
int f = 0, r = 0;

int bfs(int v)
{
    deep[v] = 1;
    quene[r++] = v;
    while (f != r)
    {
        int temp = quene[f++];
        number[deep[temp]]++;
        for (int i = 0; i < tree[temp].child.size(); i++)
        {
            int a = tree[temp].child[i];
            deep[a] = deep[temp] + 1;
            quene[r++] = a;
        }
    }
    return 0;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int temp;
        std::cin >> temp;
        std::cin >> tree[temp].k;
        for (int j = 0; j < tree[temp].k; j++)
        {
            int a;
            std::cin >> a;
            tree[temp].child.push_back(a);
        }
    }
    bfs(1);
    int max = 0;
    int j;
    for (int i = 0; i < 110; i++)
    {
        if (max < number[i])
        {
            max = number[i];
            j = i;
        }
    }
    std::cout << max << " " << j;
    return 0;
}