#include<iostream>
int visited[100100] = {0};

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        if(x>0&&x<=n)
            visited[x] = 1;
    }
    int i;
    for ( i = 1; i < n+1; i++)
    {
        if(visited[i]==0)
            break;
    }
    std::cout << i;
    return 0;
}