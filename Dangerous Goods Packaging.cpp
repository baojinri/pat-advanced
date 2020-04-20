#include<iostream>
#include<vector>
std::vector<int> a[100010];
int visited[100010] = {0};

int main()
{
    std::ios::sync_with_stdio(false);
    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 0; i < k; i++)
    {
        int temp;
        std::cin >> temp;
        int flag = 0;
        for (int j = 0; j < temp; j++)
        {
            int x;
            std::cin >> x;
            if(flag==1)
                continue;
            if(visited[x]==0)
            {
                for (int p = 0; p < a[x].size(); p++)
                {
                    visited[a[x][p]] = 1;
                }
            }
            else
            {
                flag = 1;
            }
        }
        if(flag==0)
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
        for (int j = 0; j < 100010; j++)
        {
            visited[j] = 0;
        }
    }
    
    return 0;
}