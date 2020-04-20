#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int stone[10000];
int mergeStones(int *stones, int stonesSize, int K)
{
    if ((stonesSize - K) % (K - 1) != 0)
        return -1;
    int i, j, k;
    int dp[stonesSize][stonesSize] = {{0}};
    int s[stonesSize][stonesSize];
    for (i = 0; i < stonesSize; i++)
    {
        s[i][i] = stones[i];
        for (j = i + 1; j < stonesSize; j++)
            s[i][j] = s[i][j - 1] + stones[j];
    }
    for (i = 0; i + K - 1 < stonesSize; i++)
        dp[i][i + K - 1] = s[i][i + K - 1];
    for (k = K; k < stonesSize; k++)
    {
        for (i = 0; i + k < stonesSize; i++)
            for (j = i + k - 1; j >= i; j -= (K - 1))
            {
                if ((k + 1 - K) % (K - 1) == 0)
                {
                    if (dp[i][i + k] == 0)
                        dp[i][i + k] = dp[i][j] + dp[j + 1][i + k] + s[i][i + k];
                    else
                        dp[i][i + k] = min(dp[i][i + k], dp[i][j] + dp[j + 1][i + k] + s[i][i + k]);
                }
                else
                {
                    if (dp[i][i + k] == 0)
                        dp[i][i + k] = dp[i][j] + dp[j + 1][i + k];
                    else
                        dp[i][i + k] = min(dp[i][i + k], dp[i][j] + dp[j + 1][i + k]);
                }
            }
    }
    return dp[0][stonesSize - 1];
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> stone[i];
    }
    cout << mergeStones(stone, n, k);
    return 0;
}