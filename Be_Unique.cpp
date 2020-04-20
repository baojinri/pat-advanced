#include<iostream>
int count[10010] = {0};

int main()
{
    int n;
    std::cin >> n;
    int *p = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i];
        count[p[i]]++;
    }
    int i;
    for ( i = 0; i < n; i++)
    {
        if(count[p[i]]==1)
        {
            std::cout << p[i];
            break;
        }
    }
    if(i==n)
    {
        std::cout << "None";
    }
    
}