#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
std::map<std::string, std::vector<int>> s;

int main()
{
    std::ios::sync_with_stdio(false);
    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int temp, m;
        std::cin >> temp >> m;
        for (int j = 0; j < m; j++)
        {
            std::string t;
            std::cin >> t;
            s[t].push_back(temp);
        }
    }
    for (int i = 0; i < n; i++)
    {
        std::string t;
        std::cin >> t;
        std::sort(s[t].begin(), s[t].end());
        std::cout << t << " " << s[t].size();
        for (int j = 0; j < s[t].size(); j++)
        {
            std::cout << " " << s[t][j];
        }
        std::cout << std::endl;
    }
    return 0;
}