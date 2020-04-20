#include <algorithm>
#include <iostream>
int coin[1000] = {0};

int main()
{
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        if (temp < m)
            coin[temp]++;
    }
    int flag = 0;
    for (int i = 1; i < m; i++)
    {
        if (coin[i] != 0 && coin[m - i] != 0 && i != m - i)
        {
            std::cout << i << " " << m - i;
            flag = 1;
            break;
        }
        if (i == m - i && coin[i] > 1)
        {
            std::cout << i << " " << i;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        std::cout << "No Solution";

    return 0;
}