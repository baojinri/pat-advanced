#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
std::map<std::string, std::vector<std::string>> s;
bool edage[10000][10000];
struct node
{
    std::string x, y;
} ans[350];
int count = 0;

bool cmp(node a, node b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        std::string x, y;
        std::cin >> x >> y;
        edage[abs(std::stoi(x))][abs(std::stoi(y))] = true;
        edage[abs(std::stoi(y))][abs(std::stoi(x))] = true;
        if (x.size() == y.size())
        {
            s[x].push_back(y);
            s[y].push_back(x);
        }
    }
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++)
    {
        std::string x, y;
        count = 0;
        std::cin >> x >> y;
        for (int j = 0; j < s[x].size(); j++)
        {
            if (s[x][j] != y)
            {
                for (int q = 0; q < s[y].size(); q++)
                {
                    if (s[y][q] != x)
                    {
                        if (edage[abs(std::stoi(s[x][j]))][abs(std::stoi(s[y][q]))])
                        {
                            ans[count].x = s[x][j];
                            ans[count].y = s[y][q];
                            if (ans[count].x.size() == 5)
                                ans[count].x.erase(ans[count].x.begin());
                            if (ans[count].y.size() == 5)
                                ans[count].y.erase(ans[count].y.begin());
                            count++;
                        }
                    }
                }
            }
        }
        std::sort(ans, ans + count, cmp);
        std::cout << count << std::endl;
        for (int j = 0; j < count; j++)
        {
            printf("%s %s\n", ans[j].x.c_str(), ans[j].y.c_str());
        }
    }
    return 0;
}