#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
int bills[24];
struct customes
{
    std::string name, time, tag;
};
customes cust[1010];

double cal(std::string str1, std::string str2)
{
    int day1 = 0, day2 = 0, hour1 = 0, hour2 = 0, min1 = 0, min2 = 0;
    double sum = 0.0;
    hour1 = (str1[6] - '0') * 10 + str1[7] - '0', min1 = (str1[9] - '0') * 10 + str1[10] - '0';
    hour2 = (str2[6] - '0') * 10 + str2[7] - '0', min2 = (str2[9] - '0') * 10 + str2[10] - '0';
    day1 = (str1[3] - '0') * 10 + str1[4] - '0', day2 = (str2[3] - '0') * 10 + str2[4] - '0';
    if (day1 == day2)
    {
        if (hour1 == hour2)
        {
            sum = (min2 - min1) * bills[hour1] / 100;
            std::cout << (min2 - min1) << setiosflags(ios::fixed) << setprecision(2) << " $" << sum << std::endl;
        }
        int time = 0;
        if (hour1 < hour2)
        {
            sum = bills[hour1] * (60 - min1);
            time = 60 - min1;
            for (int i = hour1 + 1; i < hour2; i++)
            {
                sum = sum + bills[i] * 60;
                time = time + 60;
            }
            sum = (sum + bills[hour2] * min2) / 100;
            time = time + min2;
            std::cout << time << " $" << setiosflags(ios::fixed) << setprecision(2) << sum << std::endl;
        }
    }
    else
    {
        int time = 0;
        sum = bills[hour1] * (60 - min1);
        time = 60 - min1;
        for (int i = hour1 + 1; i < 24; i++)
        {
            sum = sum + bills[i] * 60;
            time = time + 60;
        }
        for (int i = day1 + 1; i < day2; i++)
        {
            for (int j = 0; j < 24; j++)
            {
                sum = sum + bills[j] * 60;
                time = time + 60;
            }
        }
        for (int i = 0; i < hour2; i++)
        {
            sum = sum + bills[i] * 60;
            time = time + 60;
        }
        sum = (sum + bills[hour2] * min2) / 100;
        time = time + min2;
        std::cout << time << " $" << setiosflags(ios::fixed) << setprecision(2) << sum << std::endl;
    }

    return sum;
}

int main()
{
    for (int i = 0; i < 24; i++)
    {
        std::cin >> bills[i];
    }
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> cust[i].name >> cust[i].time >> cust[i].tag;
    }
    customes temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (cust[j].name < cust[j - 1].name)
                temp = cust[j], cust[j] = cust[j - 1], cust[j - 1] = temp;
            else if (cust[j].name == cust[j - 1].name && cust[j].time < cust[j - 1].time)
                temp = cust[j], cust[j] = cust[j - 1], cust[j - 1] = temp;
        }
    }
    int k = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (cust[i].name == cust[i + 1].name && cust[i].tag == "on-line" && cust[i + 1].tag == "off-line")
        {
            k = i;
            break;
        }
    }
    std::string name = cust[k].name;
    double total = 0;
    std::cout << name << " " << cust[k].time[0] << cust[k].time[1] << std::endl;
    for (int i = k; i < n - 1; i++)
    {
        double sum = 0;
        if (cust[i].name == cust[i + 1].name && cust[i].tag == "on-line" && cust[i + 1].tag == "off-line")
        {
            if (cust[i].name != name)
            {
                name = cust[i].name;
                std::cout << "Total amount: $" << total << std::endl;
                total = 0;
                std::cout << name << " " << cust[k].time[0] << cust[k].time[1] << std::endl;
            }
            for (int j = 3; j < 11; j++)
            {
                std::cout << cust[i].time[j];
            }
            std::cout << " ";
            for (int j = 3; j < 11; j++)
            {
                std::cout << cust[i + 1].time[j];
            }
            std::cout << " ";
            sum = cal(cust[i].time, cust[i + 1].time);
            total += sum;
        }
    }
    std::cout << "Total amount: $" << total << std::endl;
    return 0;
}