#include <iostream>
#include <string>

int main()
{
    int n;
    std::cin >> n;
    int a[100] = {0};
    for (int i = 0; i < n; i++)
    {
        std::string s;
        int sum = 0;
        std::cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            sum += (s[j] - '0');
        }
        a[sum]++;
    }
    int count = 0;
    for (int i = 0; i < 100; i++)
    {
        if (a[i] != 0)
        {
            count++;
        }
    }
    std::cout << count << std::endl;
    int count1 = 0;
    for (int i = 0; i < 100; i++)
    {
        if (a[i] != 0)
        {
            std::cout << i;
            count1++;
            if (count1 != count)
                std::cout << " ";
        }
    }
    return 0;
}