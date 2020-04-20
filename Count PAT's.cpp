#include<iostream>
#include<string>

int main()
{
    std::string s;
    std::cin >> s;
    long long  count = 0;
    long long  p = 0, a = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='P')
            p++;
        if(s[i]=='A')
            a += p;
        if(s[i]=='T')
            count += a;
    }
    std::cout << count%1000000007;
    return 0;
}