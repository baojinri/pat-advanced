#include <iostream>
#include <string>

bool isPalindromic(std::string str)
{
    int length = str.size();
    int i;
    for (i = 0; i < length / 2; i++)
    {
        if (str[i] != str[length - 1 - i])
            break;
    }
    if (i >= length / 2)
        return true;
    else
        return false;
}

std::string trans(std::string str)
{
    int length = str.size();
    std::string s=str;
    int jw = 0;
    for (int i = 0; i < length; i++)
    {
        int n = str[i] - '0';
        int m = str[length - 1 - i] - '0';
        int sum = n + m+jw;
        if (sum < 10)
        {
            s[length - 1 - i] = sum+ '0';
            jw = 0;
        }
        else
        {
            sum = sum - 10;
            s[length - 1 - i] = sum+ '0';
            jw = 1;
        }
    }
    if (jw ==1)
    {
        s = "1" + s;
    }
    return s;
}

int main()
{
    std::string str;
    int n;
    std::cin >> str >> n;
    int i;
    for (i = 0; i < n; i++)
    {
        if (isPalindromic(str))
        {
            std::cout << str << std::endl
                      << i;
            break;
        }
        str = trans(str);
    }
    if (i == n)
    {
        std::cout << str << std::endl
                  << i;
    }

    return 0;
}