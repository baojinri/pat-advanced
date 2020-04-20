#include<iostream>
int color[210];
int seq[10010];
int dp[10010];

int main()
{
    int n, m, l;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        std::cin >> color[i];
    }
    std::cin >> l;
    int count = 0;
    for (int i = 0; i < l; i++)
    {
        int x;
        std::cin >> x;
        int j;
        for ( j = 0; j< m; j++)
        {
            if(color[j]==x)
            {
                break;
            }
        }
        if(j<m)
        {
            seq[count] = j;
            count++;
        }
    }
    int ans = -1;
    for (int i = 0; i < count; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if(seq[i]>=seq[j]&&dp[i]<dp[j]+1)
            {
                dp[i] = dp[j] + 1;
            }
        }
        ans = (ans > dp[i] ? ans : dp[i]);
    }
    std::cout << ans;

    return 0;
}