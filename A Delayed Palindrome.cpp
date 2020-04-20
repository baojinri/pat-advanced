#include <iostream>
#include <string>

bool ispalind(std::string s)
{
    for (int i = 0; i < s.size() / 2; i++)
    {
        if (s[i] != s[s.size() - 1 - i])
            return false;
    }
    return true;
}

int main()
{
    std::string a;
    std::cin >> a;
    int count = 0;
    while (true)
    {
        if (ispalind(a))
        {
            std::cout << a << " is a palindromic number.";
            break;
        }
        std::string b;
        for (int i = 0; i < a.size(); i++)
        {
            b = a[i] + b;
        }
        std::string ans;
        int jw = 0;
        for (int i = a.size() - 1; i > -1; i--)
        {
            int temp = (a[i] - '0') + (b[i] - '0') + jw;
            if (temp > 9)
            {
                temp = temp - 10;
                jw = 1;
            }
            else
                jw = 0;
            ans = std::to_string(temp) + ans;
        }
        if (jw == 1)
            ans = std::to_string(jw) + ans;
        std::cout << a << " + " << b << " = " << ans << std::endl;
        count++;
        a = ans;
        if (count == 10)
        {
            break;
        }
    }
    if (count == 10 && !ispalind(a))
        std::cout << "Not found in 10 iterations.";
    else if (count == 10 && ispalind(a))
        std::cout << a << " is a palindromic number.";
    return 0;
}