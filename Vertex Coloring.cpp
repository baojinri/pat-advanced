#include<iostream>
#include<algorithm>
struct node
{
    int x, y;
}s[10010];
int a[10010];

int main()
{
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        std::cin >> s[i].x >> s[i].y;
    }
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> a[j];
        }
        int j;
        for (j = 0; j < m; j++)
        {
            if(a[s[j].x]==a[s[j].y])
                break;
        }
        if(j<m)
            std::cout << "No" << std::endl;
        else
        {
            std::sort(a, a + n);
            int count = 1;
            for (int j = 1; j < n; j++)
            {
                if(a[j]!=a[j-1])
                    count++;
            }
            std::cout << count << "-coloring" << std::endl;
        }
        
    }
    
    return 0;
}