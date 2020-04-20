#include <algorithm>
#include <iostream>
#include <string>

std::string str[10010];

bool cmp(std::string a, std::string b)
{
    return a + b < b + a;
}
int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> str[i];
    }
    std::sort(str, str + n, cmp);
    std::string s;
    for (int i = 0; i < n; i++)
    {
        s += str[i];
    }
    while (s[0]=='0'&&s.size()!=0)
    {
        s.erase(s.begin());
    }
    if (s.size() != 0)
        std::cout << s;
    else
        std::cout << '0';
    return 0;
}