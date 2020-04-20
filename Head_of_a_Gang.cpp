#include<iostream>
#include<string>

int edage[30000][30000] = {{0}};
int visited[30000] = {0};

int main()
{
    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        std::string str1, str2;
        std::cin >> str1 >> str2;
        int x, y, z;
        x = (str1[0] - 'A') * 676 + (str1[1] - 'A') * 26 + str1[2] - 'A';
        y = (str2[0] - 'A') * 676 + (str2[1] - 'A') * 26 + str2[2] - 'A';
        std::cin >> z;
        edage[x][y] += z;
        edage[y][x] += z;
    }

    
    return 0;
}