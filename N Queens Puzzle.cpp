#include<iostream>
int a[1010];
int visited[1010] = {0};

int main()
{
    std::ios::sync_with_stdio(false);
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++)
    {
        int n;
        int flag = 0;
        std::cin >> n;
        for (int j = 1; j < n+1; j++)
        {
            std::cin >> a[j];
            if(a[j]>n||visited[a[j]]==1)
            {
                flag = 1;
            }
            visited[a[j]] = 1;
        }
        for (int j = 1; j < n+1; j++)
        {
            int x = j;
            int y = a[j];
            while(x-1>0&&y-1>0)
            {
                if(a[x-1]==y-1)
                    flag = 1;
                x--;
                y--;
            }
            x = j;
            y = a[j];
            while(x+1<=n&&y+1<=n)
            {
                if(a[x+1]==y+1)
                    flag = 1;
                x++;
                y++;
            }
            x = j;
            y = a[j];
            while(x-1>0&&y+1<=n)
            {
                if(a[x-1]==y+1)
                    flag = 1;
                x--;
                y++;
            }
            x = j;
            y = a[j];
            while(x+1<=n&&y-1>0)
            {
                if(a[x+1]==y-1)
                {
                    flag = 1;
                }
                x++;
                y--;
            }
        }
        if(flag==1)
            std::cout << "NO" << std::endl;
        else
            std::cout << "YES" << std::endl;
        for (int j = 0; j < 1010; j++)
        {
            visited[j] = 0;
        }
        
    }
    
    return 0;
}