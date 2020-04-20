#include <iostream>
#include <string>

int fun(std::string s, int n)
{
    int m ;
    for (int i = s.size() - 1; i > n-1; i--)
    {
        int count = 0;
        if (s[i] == s[n])
        {
            m = i;
            while (n < m)
            {
                if (s[n] == s[m])
                {
                    n++;
                    m--;
                    count += 2;
                }
                else
                {
                    break;
                }
            }
            if (m == n)
            {
                return count + 1;
            }
            else if (n > m)
            {
                return count;
            }
        }
    }
    return 1;
}

int main()
{
    std::string s;
    getline(std::cin, s);
    int max = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int temp = fun(s, i);
        if (max < temp)
        {
            max = temp;
        }
    }
    std::cout << max;
    return 0;
}