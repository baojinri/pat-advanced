#include <iostream>
#include <map>
#include <string>
std::map<char, int> s, s2;

int main()
{
    int k;
    std::cin >> k;
    std::string t, ans, p;
    std::cin >> t;
    int num = 0;
    char temp;
    for (int i = 0; i < t.size(); i++)
    {
        if (num == 0)
        {
            temp = t[i];
            num = 1;
            continue;
        }
        if (temp == t[i])
        {
            num++;
            if (num == k)
            {
                if (s[temp] == 0)
                {
                    ans += temp;
                    if (s2[temp] == 0)
                    {
                        p += temp;
                        s2[temp] = 1;
                    }
                }
                else
                {
                    for (int j = 0; j < k; j++)
                    {
                        ans += temp;
                    }
                }
                num = 0;
            }
        }
        else
        {
            s[temp] = 1;
            for (int i = 0; i < num; i++)
            {
                ans += temp;
            }
            temp = t[i];
            num = 1;
        }
    }
    for (int i = 0; i < num; i++)
    {
        ans += temp;
    }
    std::cout << p << std::endl
              << ans;
    return 0;
}