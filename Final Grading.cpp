#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
struct node
{
    std::string name;
    double Gp = -1, Gm = -1, Gf = -1;
    int fin;
};
std::map<std::string, node> s;

bool cmp(node a, node b)
{
    if (a.fin == b.fin)
        return a.name < b.name;
    return a.fin > b.fin;
}

int main()
{
    int p, m, n;
    std::cin >> p >> m >> n;
    for (int i = 0; i < p; i++)
    {
        std::string t;
        std::cin >> t;
        s[t].name = t;
        std::cin >> s[t].Gp;
    }
    for (int i = 0; i < m; i++)
    {
        std::string t;
        std::cin >> t;
        s[t].name = t;
        std::cin >> s[t].Gm;
    }
    for (int i = 0; i < n; i++)
    {
        std::string t;
        std::cin >> t;
        s[t].name = t;
        std::cin >> s[t].Gf;
    }
    std::vector<node> ans;
    for (std::map<std::string, node>::iterator it = s.begin(); it != s.end(); it++)
    {
        if (it->second.Gp >= 200 && it->second.Gf >= 60)
        {
            if (it->second.Gm > it->second.Gf)
                it->second.fin = int(it->second.Gm * 0.4 + it->second.Gf * 0.6 + 0.5);
            else
                it->second.fin = it->second.Gf;
            ans.push_back(it->second);
        }
    }
    std::sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i].name << " "
                  << ans[i].Gp << " "
                  << ans[i].Gm << " "
                  << ans[i].Gf << " "
                  << ans[i].fin << std::endl;
    }
    return 0;
}