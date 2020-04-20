#include<iostream>

int main()
{
    int n;
    std::cin >> n;
    int *p = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i];
    }
    int temp = 0,sum=0;
    for (int i = 0; i < n; i++)
    {
        if(temp>p[i])
        {
            sum = sum + (temp - p[i]) * 4;
            temp = p[i];
        }
        else
        {
            sum = sum + (p[i] - temp) * 6;
            temp = p[i];
        }
    }
    sum = sum + n * 5;
    std::cout << sum << std::endl;
    system("pause");
    return 0;
}