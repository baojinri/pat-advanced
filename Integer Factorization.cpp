#include <cmath>
#include <iostream>
#include <vector>
std::vector<int> v,ans;
int n, k, p;
int temp[410];
int max = -1;

int dfs(int u, int sum, int deep, int summax)
{
    temp[deep] = v[u];
    sum += pow(v[u], p);
    summax += v[u];
    if (sum > n)
        return 0;
    deep++;
    if (deep > k)
        return 0;
    if (sum == n && deep == k)
    {
        if(summax>max)
        {
            max = summax;
            ans.clear();
            for (int i = 0; i < k; i++)
            {
                ans.push_back(temp[i]);
            }
            
        }
        return 0;
    }
    for (int i = u; i > -1; i--)
    {
        dfs(i, sum, deep,summax);
    }
    return 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k >> p;
    int temp = 1;
    while (pow(temp, p) <= n)
    {
        v.push_back(temp);
        temp++;
    }
    for (int i = v.size() - 1; i > -1; i--)
    {
        dfs(i, 0, 0,0);
    }
    if (max == -1)
    {
        std::cout << "Impossible";
    }
    else
    {
        std::cout << n << " = ";
        for (int i = 0; i < k; i++)
        {
            std::cout << ans[i] << "^" << p;
            if (i != k - 1)
            {
                std::cout << " + ";
            }
        }
    }

    return 0;
}