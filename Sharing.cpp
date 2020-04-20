#include <iostream>
#include <string>
int list[99999] = {-2};

int main()
{

    int n, str1, str2;
    std::cin >> str1 >> str2 >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        char x;
        std::cin >> temp >> x;
        std::cin >> list[temp];
    }
    int count1 = 0, count2 = 0;
    int p = str1;
    while (p != -1)
    {
        p = list[p];
        count1++;
    }
    p = str2;
    while (p != -1)
    {
        p = list[p];
        count2++;
    }
    int count = 0;
    p = str1;
    int q = str2;
    while (p != q)
    {
        count++;
        if (count > count2 - count1)
            p = list[p];
        if (count > count1 - count2)
            q = list[q];
    }
    if (p != -1)
    {

        for (int i = 0; i < 5 - std::to_string(p).size(); i++)
        {
            std::cout << "0";
        }
    }
    std::cout << p;
    return 0;
}