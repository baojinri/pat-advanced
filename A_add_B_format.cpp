#include <iostream>
int transfer(int);

int main()
{
    int a = 0, b = 0;
    std::cin >> a;
    std::cin >> b;
    int sum;
    sum = a + b;
    if(sum<0)
    {
        sum = 0 - sum;
        std::cout << '-';
    }
    if (sum / 1000 != 0)
    {{
        transfer(sum/1000);
    }
       sum = sum % 1000;
    if(sum/1==0)
    {
        std::cout << '0' << '0' << sum;
    }
    else if(sum/10==0)
    {
         std::cout << '0' <<'0' << sum;
    }
    else if(sum/100==0)
    {
        std::cout << '0' << sum;
    }
    else 
    { 
         std::cout<< sum; 
    }}
    else 
    {
        std::cout << sum;
    }
    system("pause");
    return 0;
}
int transfer(int n)
{
    if (n/1000 != 0)
    {{
        transfer(n / 1000);
    }
       n = n % 1000;
    if(n/1==0)
    {
        std::cout << '0' << '0' << n<<',';
    }
    else if(n/10==0)
    {
         std::cout << '0' <<',' << n<<',';
    }
    else if(n/100==0)
    {
        std::cout << '0' << n<<',';
    }
    else 
    { 
         std::cout<< n<<',';
    }}
    else
    {
        std::cout << n <<',';
    }
    return 0;
}