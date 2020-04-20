#include <cstdio>
#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    long long sum = 1, sum2 = 0,a,b;
    for (int i = 0; i < n; i++)
    {
        scanf("%d/%d",&a ,&b );
        a = a * sum;
        sum = sum * b;
        sum2 = sum2 * b;
        sum2 = sum2 + a;
    }
    long int x = sum2 / sum;
    sum2 = sum2 % sum;
    if (sum2 != 0)
    {
        int i = 2;
        while (i < sum)
        {
            if (sum2 % i == 0 && sum % i == 0)
            {
                sum2 = sum2 / i;
                sum = sum / i;
                i = 2;
            }
            i++;
        }
    }
    if (a != 0&&sum2!=0)
    {
        std::cout << a << " ";
    }
    else if(a!=0&&sum2==0)
        std::cout << a;
    if (sum2 != 0)
        std::cout << sum2 << "/" << sum;

    return 0;
}