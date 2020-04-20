#include <iostream>
#include <string>

struct students
{
    std::string name, password;
};

bool modify(std::string &s)
{
    int length = s.size();
    int flag = 0;
    for (int i = 0; i < length; i++)
    {
        if (s[i] == '1')
        {
            s.replace(i, 1, "@");
            flag = 1;
        }
        else if (s[i] == '0')
        {
            s.replace(i, 1, "%");
            flag = 1;
        }
        else if (s[i] == 'l')
        {
            s.replace(i, 1, "L");
            flag = 1;
        }
        else if (s[i] == 'O')
        {
            s.replace(i, 1, "o");
            flag = 1;
        }
    }
    if (flag == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int n;
    std::cin >> n;
    students *s = new students[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> s[i].name >> s[i].password;
    }
    int visited[1000] = {-1};
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        int flag = modify(s[i].password);
        if (flag)
        {
            visited[j] = i;
            j++;
        }
    }
    if (j == 0)
    {
        if (n > 1)
        {
            std::cout << "There are " << n << " accounts and no account is modified";
        }
        else
        {
            std::cout << "There is " << n << " account and no account is modified";
        }
    }
    else
    {
        std::cout << j << std::endl;
        for (int i = 0; i < j; i++)
        {
            std::cout << s[visited[i]].name << " " << s[visited[i]].password << std::endl;
        }
    }

    return 0;
}