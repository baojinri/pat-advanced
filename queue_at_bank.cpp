#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
struct customer
{
    std::string arr;
    int minute;
    std::string fin;
};
customer cust[10010];
int window[110] = {0};

double cal(std::string str1, std::string str2)
{
    double minute1, minute2;
    double scend1, scend2;
    scend1 = (str1[6] - '0') * 10 + str1[7] - '0';
    scend2 = (str2[6] - '0') * 10 + str2[7] - '0';
    minute1 = ((str1[0] - '0') * 10 + str1[1] - '0') * 60 + (str1[3] - '0') * 10 + str1[4] - '0';
    minute1 += scend1 / 60;
    minute2 = ((str2[0] - '0') * 10 + str2[1] - '0') * 60 + (str2[3] - '0') * 10 + str2[4] - '0';
    minute2 += scend2 / 60;
    return (minute2 - minute1);
}

std::string cal(std::string str, int n)
{
    int minute = (str[3] - '0') * 10 + str[4] - '0';
    minute += n;
    if (minute < 60)
    {
        str.replace(3, 2, std::to_string(minute));
    }
    else
    {
        minute = minute - 60;
        str.replace(3, 2, std::to_string(minute));
        int hour = (str[0] - '0') * 10 + str[1] - '0' + 1;
        str.replace(0, 2, std::to_string(hour));
    }
    return str;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n, k;
    double sum = 0;
    int count = 0;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        std::cin >> cust[i].arr >> cust[i].minute;
    }
    customer temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (cust[j].arr < cust[j - 1].arr)
            {
                temp = cust[j];
                cust[j] = cust[j - 1];
                cust[j - 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (cust[i].arr > "17:00:00")
        {
            n = i;
            break;
        }
    }

    if (n <= k)
    {
        for (int i = 0; i < n; i++)
        {
            if (cust[i].arr < "08:00:00")
            {
                sum += cal(cust[i].arr, "08:00:00");
                count++;
            }
            else
                count++;
        }
        sum = sum / count;
        std::cout << setiosflags(ios::fixed) << setprecision(1) << sum;
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            if (cust[i].arr < "08:00:00")
            {
                sum += cal(cust[i].arr, "08:00:00");
                count++;
                cust[i].fin = cal("08:00:00", cust[i].minute);
                window[i] = i;
            }
            else
            {
                count++;
                cust[i].fin = cal(cust[i].arr, cust[i].minute);
                window[i] = i;
            }
        }
        for (int i = k; i < n; i++)
        {
            std::string min = "24:00:00";
            int p = -1;
            for (int j = 0; j < k; j++)
            {
                if (cust[window[j]].fin < min)
                {
                    min = cust[window[j]].fin;
                    p = j;
                }
            }
            if (cust[i].arr < cust[window[p]].fin)
            {
                sum += cal(cust[i].arr, cust[window[p]].fin);
                count++;
                cust[i].fin = cal(cust[window[p]].fin, cust[i].minute);
                window[p] = i;
            }
            else
            {
                count++;
                cust[i].fin = cal(cust[i].arr, cust[i].minute);
                window[p] = i;
            }
        }
        sum = sum / count;
        std::cout << setiosflags(ios::fixed) << setprecision(1) << sum;
    }

    return 0;
}