#include <iostream>
#include <string>
struct list
{
    int adress, date, next;
};
list l[100000];
int count = 0;
int temp;
int flag = 0;

int reverse(int adress, int k)
{
    count++;
    if (count == k)
    {
        if (flag == 1)
        {
            std::string s = std::to_string(adress);
            for (int i = 0; i < 5 - s.size(); i++)
            {
                std::cout << 0;
            }
            std::cout << adress << std::endl;
        }
        flag = 1;
        temp = l[adress].next;
        std::string s = std::to_string(adress);
        for (int i = 0; i < 5 - s.size(); i++)
        {
            std::cout << 0;
        }

        std::cout << adress << " " << l[adress].date << " ";
        return 0;
    }
    reverse(l[adress].next, k);
    std::string s = std::to_string(adress);
    for (int i = 0; i < 5 - s.size(); i++)
    {
        std::cout << 0;
    }
    std::cout << adress << std::endl;
    s = std::to_string(adress);
    for (int i = 0; i < 5 - s.size(); i++)
    {
        std::cout << 0;
    }
    std::cout << adress << " " << l[adress].date << " ";
    return 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n, k, adress;
    std::cin >> adress >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        std::cin >> l[temp].date >> l[temp].next;
        l[temp].adress = temp;
    }
    int sum = 0;
    int p = adress;
    while (p != -1)
    {
        sum++;
        p = l[p].next;
    }
    sum = sum / k;
    for (int i = 0; i < sum; i++)
    {
        count = 0;
        reverse(adress, k);
        adress = temp;
    }
    while (adress != -1)
    {
        std::string s = std::to_string(adress);
        for (int i = 0; i < 5 - s.size(); i++)
        {
            std::cout << 0;
        }
        std::cout << adress << std::endl;
        s = std::to_string(adress);
        for (int i = 0; i < 5 - s.size(); i++)
        {
            std::cout << 0;
        }
        std::cout << adress << " " << l[adress].date << " ";
        adress = l[adress].next;
    }
    std::cout << -1;
    return 0;
}
/*
00100 6 2
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218*/