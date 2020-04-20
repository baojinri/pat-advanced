#include <cmath>
#include <iomanip>
#include <iostream>
struct node
{
    int k;
    int *c = new int[k];
    int customer;
};
node s[100010];
double p, r, sum = 0;

int dfs(int v, int deep)
{
    if (s[v].k == 0)
    {
        sum += p * s[v].customer * pow(1 + (r / 100), deep);
        return 0;
    }
    for (int i = 0; i < s[v].k; i++)
    {
        dfs(s[v].c[i], deep + 1);
    }

    return 0;
}

int main()
{
    int n;
    std::cin >> n >> p >> r;
    for (int i = 0; i < n; i++)
    {
        std::cin >> s[i].k;
        for (int j = 0; j < s[i].k; j++)
        {
            std::cin >> s[i].c[j];
        }
        if (s[i].k == 0)
        {
            std::cin >> s[i].customer;
        }
    }
    dfs(0, 0);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1) << sum;
    return 0;
}