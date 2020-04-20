#include <iostream>
struct wz
{
    int f, r;
};

int seq[10000] = {0};
wz flag[10000];
int dp[10000];

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> seq[i];
    }
    dp[0] = seq[0];
    flag[0].f = 0;
    flag[0].r = 0;
    for (int i = 1; i < n; i++)
    {
        if (seq[i] > dp[i - 1] + seq[i])
        {
            dp[i] = seq[i];
            flag[i].f = i;
            flag[i].r = i;
        }
        else
        {
            dp[i] = dp[i - 1] + seq[i];
            flag[i].f = flag[i - 1].f;
            flag[i].r = i;
        }
    }
    int j, max = -10000000;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > max)
        {
            max = dp[i];
            j = i;
        }
    }
    if(dp[j]<0)
    {
        std::cout << 0 << " " << seq[0] << " " << seq[n - 1];
        return 0;
    }
    std::cout << dp[j] << " " << seq[flag[j].f] << " " << seq[flag[j].r];

    return 0;
}