#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
struct node
{
    std::string name;
    int num;
};
std::vector<node> ans;
std::map<std::string, int> a;
int edage[10010][10010] = {{0}};
int visitde[10010] = {0};
int count = 1;
std::vector<int> p;

bool cmp(node a, node b)
{
    return a.name < b.name;
}

int dfs(int v)
{
    visitde[v] = 1;
    p.push_back(v);
    for (int i = 1; i < count; i++)
    {
        if (visitde[i] == 0 && edage[v][i] != 0)
            dfs(i);
    }
    return 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        std::string x, y;
        std::cin >> x >> y;
        if (a[x] == 0)
            a[x] = count++;
        if (a[y] == 0)
            a[y] = count++;
        int temp;
        std::cin >> temp;
        edage[a[x]][a[y]] += temp;
        edage[a[y]][a[x]] += temp;
    }
    for (int i = 1; i < count; i++)
    {
        if (visitde[i] == 0)
        {
            dfs(i);
            if (p.size() > 2)
            {
                int sum = 0;
                int max = 0;
                int flag;
                for (int j = 0; j < p.size(); j++)
                {
                    int sum2 = 0;
                    for (int q = 1; q < count; q++)
                    {
                        sum += edage[p[j]][q];
                        sum2 += edage[p[j]][q];
                    }
                    if (sum2 > max)
                    {
                        max = sum2;
                        flag = p[j];
                    }
                }
                if (sum / 2 > k)
                {
                    std::string s;
                    for (std::map<std::string, int>::iterator it = a.begin(); it != a.end(); it++)
                    {
                        if (it->second == flag)
                            s = it->first;
                    }
                    node temp;
                    temp.name = s;
                    temp.num = p.size();
                    ans.push_back(temp);
                }
            }
            p.clear();
        }
    }
    std::sort(ans.begin(), ans.end(), cmp);
    std::cout << ans.size() << std::endl;
    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i].name << " " << ans[i].num << std::endl;
    }

    return 0;
}