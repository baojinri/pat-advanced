#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
struct node
{
    int grade;
    std::string s;
} s[10010];
struct date
{
    int site;
    int count = 0;
};
std::map<std::string, std::vector<std::string>> s3;

bool cmp1(node a, node b)
{
    if (a.grade == b.grade)
        return a.s < b.s;
    return a.grade > b.grade;
}

bool cmp2(date a, date b)
{
    if (a.count == b.count)
        return a.site < b.site;
    return a.count > b.count;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        std::string t;
        std::cin >> t >> s[i].grade;
        s[i].s = t;
        s3[t.substr(4, 6)].push_back(t.substr(1, 3));
    }
    std::sort(s, s + n, cmp1);
    for (int i = 0; i < m; i++)
    {
        int temp;
        std::string t;
        std::cin >> temp >> t;
        if (temp == 1)
        {
            std::cout << "Case " << i + 1 << ": " << temp << " " << t << std::endl;
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (s[j].s.substr(0, 1) == t)
                {
                    printf("%s %d\n", s[j].s.c_str(), s[j].grade);
                    count++;
                }
            }
            if (count == 0)
                std::cout << "NA" << std::endl;
        }
        else if (temp == 2)
        {
            std::cout << "Case " << i + 1 << ": " << temp << " " << t << std::endl;
            int count = 0, sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (s[j].s.substr(1, 3) == t)
                {
                    sum += s[j].grade;
                    count++;
                }
            }
            if (count == 0)
                std::cout << "NA" << std::endl;
            else
                std::cout << count << " " << sum << std::endl;
        }
        else if (temp == 3)
        {
            std::map<std::string, int> ans;
            std::cout << "Case " << i + 1 << ": " << temp << " " << t << std::endl;
            for (int j = 0; j < s3[t].size(); j++)
            {
                ans[s3[t][j]]++;
            }
            std::vector<date> p;
            for (std::map<std::string, int>::iterator it = ans.begin(); it != ans.end(); it++)
            {
                date temp;
                temp.site = std::stoi(it->first);
                temp.count = it->second;
                p.push_back(temp);
            }
            if (p.size() == 0)
                std::cout << "NA" << std::endl;
            else
            {
                std::sort(p.begin(), p.end(), cmp2);
                for (int j = 0; j < p.size(); j++)
                {
                    printf("%d %d\n", p[j].site, p[j].count);
                }
            }
        }
    }

    return 0;
}