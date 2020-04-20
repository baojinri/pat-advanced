#include<iostream>
#include<iomanip>
double a[1001] = {0}, b[1001] = {0}, c[2001] = {0};

int main()
{
    int k1, k2,n;
    std::cin >> k1;
    for (int i = 0; i < k1; i++)
    {
        std::cin >> n;
        std::cin >> a[n];
    }
    std::cin >> k2;
    for (int i = 0; i < k2; i++)
    {
        std::cin >> n;
        std::cin >> b[n];
    }
    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            c[i + j] =c[i + j]+ a[i] * b[j];
        }
        
    }
    int k = 0;
    for (int i = 0; i < 2001; i++)
    {
        if(c[i]!=0)
            k++;
    }
    if (k!=0)
    {
        std::cout << k << " ";
    }
    else
    {
        std::cout << k;
    }
    for (int i = 2000; i>=0; i--)
    {
        if (c[i]!=0)
        {
            k--;
            if (k>0)
            {
                
                std::cout << i << " "<<std::setiosflags(std::ios::fixed)<<std::setprecision(1)<<c[i] << " ";
            }
            else
            {
                
                std::cout << i << " "<<std::setiosflags(std::ios::fixed)<<std::setprecision(1)<< c[i];
            }
            
        }
        
    }
    system("pause");
    return 0;
}