#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
std::map<int, std::vector<std::string>> s;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        std::string t;
        int m;
        std::cin >> t;
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
        {
            int temp;
            scanf("%d", &temp);
            s[temp].push_back(t);
        }
    }
    for (int i = 1; i < k + 1; i++)
    {
        int temp = s[i].size();
        printf("%d %d\n", i, temp);
        std::sort(s[i].begin(), s[i].end());
        for (int j = 0; j < s[i].size(); j++)
        {
            printf("%s\n", s[i][j].c_str());
        }
    }
    return 0;
}