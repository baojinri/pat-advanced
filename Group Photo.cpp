#include <algorithm>
#include <iostream>
#include <string>
struct student
{
    std::string name;
    int height;
};
student s[10010];
std::string ans[10000];

bool cmp(student a, student b)
{
    if (a.height == b.height)
        return a.name < b.name;
    return a.height > b.height;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        std::cin >> s[i].name >> s[i].height;
    }
    std::sort(s, s + n, cmp);
    int number = n / k;
    int lastnumber = number + n % k;
    int count = 0;
    ans[lastnumber / 2] = s[count++].name;
    int i = 1;
    while (true)
    {
        if (count == lastnumber)
            break;
        ans[lastnumber / 2 - i] = s[count++].name;
        if (count == lastnumber)
            break;
        ans[lastnumber / 2 + i] = s[count++].name;
        i++;
    }
    for (int i = 0; i < lastnumber; i++)
    {
        std::cout << ans[i];
        if (i != lastnumber - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    for (int i = 1; i < k; i++)
    {
        ans[number / 2] = s[count++].name;
        int num = 1;
        int p = 1;
        while (true)
        {
            if (num == number)
                break;
            ans[number / 2 - p] = s[count++].name;
            num++;
            if (num == number)
                break;
            ans[number / 2 + p] = s[count++].name;
            num++;
            p++;
        }
        for (int j = 0; j < number; j++)
        {
            std::cout << ans[j];
            if (j != number - 1)
                std::cout << " ";
            else
                std::cout << std::endl;
        }
    }

    return 0;
}