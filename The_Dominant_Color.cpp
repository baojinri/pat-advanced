#include <iostream>
int a[810][610];

int main()
{
    int m, n;
    std::cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp = a[i][j];
            int count = 0;
            for (int p = 0; p < m; p++)
            {
                for (int q = 0; q < n; q++)
                {
                    if (a[p][q] == temp)
                    {
                        count++;
                    }
                    if (count > (m * n ) / 2)
                    {
                        std::cout << temp;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}