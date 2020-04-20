#include <iostream>
int a[1010];
int count = 0;
int n;

int preorder(int v)
{
    if(v*2+1<n)
        preorder(v * 2 + 1);
    if(v*2+2<n)
        preorder(v * 2 + 2);
    count++;
    std::cout << a[v];
    if(count==n)
    {
        std::cout << std::endl;
    }
    else
    {
        std::cout << " ";
    }
    return 0;
}

int main()
{
    int k;
    std::cin >> k >> n;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> a[j];
        }
        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (j * 2 + 1 < n)
            {
                if (a[j] < a[j * 2 + 1])
                    flag = 1;
            }
            if (j * 2 + 2 < n)
            {
                if (a[j] < a[j * 2 + 2])
                    flag = 1;
            }
        }
        if (flag == 0)
            std::cout << "Max Heap" << std::endl;
        else
        {
            flag = 0;
            for (int j = 0; j < n; j++)
            {
                if (j * 2 + 1 < n)
                {
                    if (a[j] > a[j * 2 + 1])
                        flag = 1;
                }
                if (j * 2 + 2 < n)
                {
                    if (a[j] > a[j * 2 + 2])
                        flag = 1;
                }
            }
            if (flag == 0)
                std::cout << "Min Heap" << std::endl;
            else
                std::cout << "Not Heap" << std::endl;
        }
        count = 0;
        preorder(0);
    }

    return 0;
}