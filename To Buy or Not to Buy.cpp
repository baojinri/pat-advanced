#include <iostream>
#include <string>

int main()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;
    int flag = 0, count = 0;
    int visited[1000] = {0};
    for (int i = 0; i < s2.size(); i++)
    {
        int j;
        for (j = 0; j < s1.size(); j++)
        {
            if (s2[i] == s1[j] && visited[j] == 0)
            {
                visited[j] = 1;
                break;
            }
        }
        if (j == s1.size())
        {
            flag = 1;
            count++;
        }
    }
    if (flag == 0)
    {
        std::cout << "Yes"
                  << " " << s1.size() - s2.size();
    }
    else
    {
        std::cout << "No"
                  << " " << count;
    }
    return 0;
}