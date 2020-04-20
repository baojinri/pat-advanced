#include <iostream>
#include <string>

int main()
{
    int n;
    std::string s;
    std::cin >> s >> n;
    for (int i = 1; i < n; i++)
    {
        std::string temp;
        int count = 0;
        int p = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == s[p])
                count++;
            else
            {
                temp += s[p];
                temp += (count + '0');
                p = j;
                count = 1;
            }
        }
        temp += s[p];
        temp += (count + '0');
        s = temp;
    }
    std::cout << s;
    return 0;
}