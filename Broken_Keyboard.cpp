#include <iostream>
#include <string>

int main()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;
    char c[100];
    int count = 0;
    int i = 0, j = 0;
    while (j < s2.size())
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            int flag = 0;
            if (s1[i] >= 'a' && s1[i] <= 'z')
            {
                s1[i] = s1[i] - 32;
            }
            for (int k = 0; k < count; k++)
            {
                if (s1[i] == c[k])
                    flag = 1;
            }
            if (flag == 0)
            {
                std::cout << s1[i];
                c[count] = s1[i];
                count++;
            }
            flag = 0;
            i++;
        }
    }
    while (i < s1.size())
    {
        int flag = 0;
        if (s1[i] >= 'a' && s1[i] <= 'z')
        {
            s1[i] = s1[i] - 32;
        }
        for (int k = 0; k < count; k++)
        {

            if (s1[i] == c[k])
                flag = 1;
        }
        if (flag == 0)
        {
            std::cout << s1[i];
            c[count] = s1[i];
            count++;
        }
        flag = 0;
        i++;
    }

    return 0;
}