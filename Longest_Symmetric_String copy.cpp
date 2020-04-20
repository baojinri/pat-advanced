#include <iostream>
#include <string>
int dp[1010][1010] = {0};

int main()
{
    std::ios::sync_with_stdio(false);
    std::string s;
    std::getline(std::cin, s);
    int length = s.size();
    int ans=0;
    for (int i = 0; i < length; i++)
    {
        dp[i][i] = 1;
        ans = 1;
        if (i + 1 < length && s[i] == s[i + 1])
        {
            dp[i][i + 1] = 1;
            ans = 2;
        }
    }

    for (int i = 3; i <= length; i++)
    {
        for (int j = 0; j+i-1 < length; j++)
        {
            if (s[j] == s[i - 1 + j] && dp[j + 1][i + j-2] == 1)
            {
                dp[j][i - 1 + j] = 1;
                ans = i;
            }
        }
    }
    std::cout << ans;
    return 0;
}