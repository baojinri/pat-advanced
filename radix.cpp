#include <iostream>
#include <math.h>
#include <string>

int main()
{
    std::string str1, str2, temp;
    int tag, radix;
    std::cin >> str1 >> str2 >> tag >> radix;
    if (tag == 2)
    {
        temp = str1;
        str1 = str2;
        str2 = temp;
    }
    int n1 = str1.size();
    int sum1 = 0, sum2 = 0;
    for (int i = n1 - 1; i >= 0; i--)
    {
        if (str1[i] <= '9')
        {
            sum1 = sum1 + pow(radix, n1 - 1 - i) * (str1[i] - '0');
        }
        else
        {
            sum1 = sum1 + pow(radix, n1 - 1 - i) * (str1[i] - 'a' + 10);
        }
    }
    int n2 = str2.size();
    int max = 0, n = 0;
    for (int i = 0; i < n2; i++)
    {
        if (str2[i] <= '9')
        {
            n = str2[i] - '0';
        }
        else
        {
            n = str2[i] - 'a' + 10;
        }
        if (n > max)
            max = n;
    }
    int i;
    for (i = max + 1; i < 37; i++)
    {
        for (int j = n2 - 1; j >= 0; j--)
        {
            if (str2[j] <= '9')
            {
                sum2 = sum2 + pow(i, n2 - 1 - j) * (str2[j] - '0');
            }
            else
            {
                sum2 = sum2 + pow(i, n2 - 1 - j) * (str2[j] - 'a' + 10);
            }
        }
        if (sum1 == sum2)
            break;
    }
    if (i < 37)
        std::cout << i << std::endl;
    else
        std::cout << "Impossible" << std::endl;

    system("pause");
    return 0;
}