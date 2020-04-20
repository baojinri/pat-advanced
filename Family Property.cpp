#include <algorithm>
#include <iomanip>
#include <iostream>
int father[10010];
struct node
{
    double num = 1;
    double set = 0, are = 0;
} flag[10010];
int visited[10010] = {0};
struct Ans
{
    int name;
    double num;
    double set, are;
} ans[10010];
int count = 0;

bool cmp(Ans a, Ans b)
{
    if (a.are / a.num == b.are / b.num)
        return a.name < b.name;
    return a.are / a.num > b.are / b.num;
}

int findfather(int v)
{
    while (father[v] != v)
    {
        v = father[v];
    }
    return v;
}

int Union(int x, int y)
{
    int a = findfather(x);
    int b = findfather(y);
    if (a != b)
    {
        if (a < b)
            father[b] = a;
        else
            father[a] = b;
    }
    return 0;
}

int main()
{
    for (int i = 0; i < 10010; i++)
    {
        father[i] = i;
    }
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp, f;
        std::cin >> temp >> f;
        visited[temp] = 1;
        if (f != -1)
        {
            visited[f] = 1;
            Union(temp, f);
        }
        std::cin >> f;
        if (f != -1)
        {
            visited[f] = 1;
            Union(temp, f);
        }
        int m;
        std::cin >> m;
        for (int j = 0; j < m; j++)
        {
            int f;
            std::cin >> f;
            visited[f] = 1;
            Union(temp, f);
        }
        std::cin >> flag[temp].set >> flag[temp].are;
    }
    for (int i = 0; i < 10010; i++)
    {
        if (visited[i] == 1 && father[i] != i)
        {
            flag[findfather(i)].num++;
            flag[findfather(i)].set += flag[i].set;
            flag[findfather(i)].are += flag[i].are;
        }
    }

    for (int i = 0; i < 10010; i++)
    {
        if (visited[i] == 1 && father[i] == i)
        {
            ans[count].name = i;
            ans[count].num = flag[i].num;
            ans[count].set = flag[i].set;
            ans[count].are = flag[i].are;
            count++;
        }
    }
    std::sort(ans, ans + count, cmp);
    std::cout << count << std::endl;
    for (int i = 0; i < count; i++)
    {
        printf("%04d", ans[i].name);
        std::cout << " "
                  << std::setiosflags(std::ios::fixed) << std::setprecision(0) << ans[i].num << " "
                  << std::setiosflags(std::ios::fixed) << std::setprecision(3) << ans[i].set / ans[i].num << " "
                  << std::setiosflags(std::ios::fixed) << std::setprecision(3) << ans[i].are / ans[i].num << std::endl;
    }

    return 0;
}