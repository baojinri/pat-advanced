#include<iostream>
#include<iomanip>

int show(int n)
{
    if(n==0)
        std::cout << 'W'<<" ";
    else if(n==1)
        std::cout << 'T'<<" ";
    else
        std::cout << 'L'<<" ";
    return 0;
}

int main()
{
    double a[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cin >> a[i][j];
        } 
    }
    double max1 = 0, max2 = 0, max3 = 0;
    int m, n, p;
    for (int i = 0; i < 3; i++)
    {
        if(a[0][i]>max1)
            m=i,max1 = a[0][i];
    }
    for (int i = 0; i < 3; i++)
    {
        if(a[1][i]>max2)
            n=i,max2 = a[1][i];
    }
    for (int i = 0; i < 3; i++)
    {
        if(a[2][i]>max3)
            p=i,max3= a[2][i];
    }
    show(m);
    show(n);
    show(p);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << (max1 * max2 * max3 * 0.65 - 1) * 2 << std::endl;
    system("pause");
    return 0;
}