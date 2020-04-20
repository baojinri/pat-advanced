#include <iostream>

int chain[100010];
int a[100010];

int main()
{
    std::ios::sync_with_stdio(false);
    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        std::cin >> chain[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = 1000000;
    }
    
    int flag = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        sum = 0;
        while (j>=i)
        {
            sum += chain[j];
            if (sum == k)
            {
                std::cout << i+1 << "-" << j+1<<std::endl;
                flag = 1;
                break;
            }
            else if (sum > k)
            {
                a[i] = sum;
                break;
            }
            j = (j + 1) % n;
        }
    }
    if (flag == 0)
    {
        int min = 10000000;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < min)
                min = a[i];
        }
        for (int i = 0; i < n; i++)
        {
            int j = i;
            sum = 0;
            while (j>=i)
            {
                sum += chain[j];
                if (sum == min)
                {
                    std::cout << i+1 << "-" << j+1<<std::endl;
                    break;
                }
                else if (sum > k)
                {
                    break;
                }
                j = (j + 1) % n;
            }
        }
    }

    return 0;
}