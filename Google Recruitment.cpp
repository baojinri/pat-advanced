#include <cmath>
#include <iostream>
#include <string>

bool isprime(long long n)
{
    if(n==1||n==0)
        return false;
    for (long long i = 2; i*i <= n; i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    long long ans = 0;
    int flag = 0;
    
    for (int i = 0; i <= n - k; i++)
    {
        ans = 0;
        std::string t = s.substr(i, k);
        ans = std::stoi(t);
        if(isprime(ans))
        {
            std::cout << ans;
            flag = 1;
            break;
        }
    }
    if(flag==0)
    {
        std::cout << 404;
    }
    return 0;
}