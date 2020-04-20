#include <iostream>
int a[1010];
int path[1010];
int n;

int order(int v, int deep)
{
    path[deep] = a[v];
    if (v * 2 + 1 >= n)
    {
        for (int i = 0; i < deep; i++)
        {
            std::cout << path[i] << " ";
        }
        std::cout << path[deep] << std::endl;
        return 0;
    }
    if (v * 2 + 2 < n)
        order(v * 2 + 2, deep + 1);
    if (v * 2 + 1 < n)
        order(v * 2 + 1, deep + 1);

    return 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    order(0, 0);
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (i * 2 + 1 < n && a[i] < a[i * 2 + 1])
        {
            flag = 1;
            break;
        }
        if (i * 2 + 2 < n && a[i] < a[i * 2 + 2])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        std::cout << "Max Heap" << std::endl;
    }
    else
    {
        flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (i * 2 + 1 < n && a[i] > a[i * 2 + 1])
            {
                flag = 1;
                break;
            }
            if (i * 2 + 2 < n && a[i] > a[i * 2 + 2])
            {
                flag = 1;
                break;
            }
        }
        if(flag==0)
            std::cout << "Min Heap" << std::endl;
        else
            std::cout<<"Not Heap" << std::endl;
    }
    return 0;
}