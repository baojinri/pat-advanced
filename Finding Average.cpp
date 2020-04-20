#include <cmath>
#include <iostream>
#include <string>
#include<algorithm>
double sum = 0, count = 0;

bool judge(std::string s)
{
    std::string t = s;
    if (s[0] == '-')
        s.erase(s.begin());
    int count1 = 0, j = s.size();
    std::string temp;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            temp += s[i];
        else if (s[i] == '.')
        {
            count1++;
            j = i;
            if (count1 == 2)
                return false;
        }
        else
        {
            return false;
        }
    }
    if (s.size() - j > 3)
        return false;
    double x=std::stof(t);
    if(x>1000||x<-1000)
        return false;
    sum += x;
    count++;
    return true;
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;
        if (!judge(s))
            std::cout << "ERROR: " << s << " is not a legal number" << std::endl;
    }
    if (count == 1)
    {
        std::cout << "The average of 1 number is ";
        printf("%0.2f", sum);
    }
    else if (count == 0)
        std::cout << "The average of 0 numbers is Undefined";
    else
    {
        std::cout << "The average of " << count << " numbers is ";
        printf("%0.2f", sum / count);
    }
    return 0;
}