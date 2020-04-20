#include <algorithm>
#include <cmath>
#include <iostream>
int a[10010];
int ans[110][110];

bool cmp(int a,int b)
{
    return a > b;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int k;
    std::cin >> k;
    int m, n;
    n = sqrt(k);
    while (k%n!=0)
    {
        n--;
    }
    m = k / n;
    for (int i = 0; i < k; i++)
    {
        std::cin >> a[i];
    }
    std::sort(a, a + k, cmp);
    int count = 0;
    int level = n / 2;
    for (int i = 0; i < level; i++)
    {
        for (int j = i; j <n-i ; j++)
        {
            ans[i][j] = a[count++];
        }
        for (int j = i+1; j < m-i; j++)
        {
            ans[j][n - i - 1] = a[count++];
        }
        for (int j = n-i-2; j >=i; j--)
        {
            ans[m - 1 - i][j] = a[count++];
        }
        for (int j = m-i-2; j > i; j--)
        {
            ans[j][i] = a[count++];
        }
    }
    if(n%2==1)
    {
        for (int i = level;  ; i++)
        {
            ans[i][level] = a[count++];
            if(count==k)
                break;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << ans[i][j];
            if(j!=n-1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}