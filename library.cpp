#include <iostream>
#include <string>
struct book
{
    std::string id, title, author, key[5], publish, year;
};

int main()
{
    int n, m;
    std::cin >> n;
    std::string stri;
    std::getline(std::cin, stri);
    book *p = new book[n];
    for (int i = 0; i < n; i++)
    {
        std::getline(std::cin, p[i].id);
        std::getline(std::cin, p[i].title);
        std::getline(std::cin, p[i].author);
        std::string str;
        std::getline(std::cin, str);
        int k = 0;
        int count = str.size();
        for (int j = 0; j < count;)
        {
            while (str[j] != ' ' && j < count)
            {
                p[i].key[k] += str[j];
                j++;
            }
            k++;
            j++;
        }
        std::getline(std::cin, p[i].publish);
        std::getline(std::cin, p[i].year);
    }
    book temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (p[j].id < p[j - 1].id)
                temp = p[j], p[j] = p[j - 1], p[j - 1] = temp;
        }
    }

    std::cin >> m;
    std::getline(std::cin, stri);
    std::string q[1000];
    for (int i = 0; i < m; i++)
    {
        std::getline(std::cin, q[i]);
    }
    std::string g[1000];
    for (int i = 0; i < m; i++)
    {
        int count = q[i].size();
        for (int j = 3; j < count; j++)
        {
            g[i] += q[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        std::cout << q[i] << std::endl;
        int it = 0;
        std::string flag;
        flag = q[i][0];
        if (flag == "1")
        {
            for (int j = 0; j < n; j++)
            {
                if (p[j].title == g[i])
                    std::cout << p[j].id << std::endl, it = 1;
            }
            if (it == 0)
                std::cout << "Not Found" << std::endl;
        }
        else if (flag == "2")
        {
            for (int j = 0; j < n; j++)
            {
                if (p[j].author == g[i])
                    std::cout << p[j].id << std::endl, it = 1;
            }
            if (it == 0)
                std::cout << "Not Found" << std::endl;
        }
        else if (flag == "3")
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < 5; k++)
                {
                    if (p[i].key[k] == g[i])
                        std::cout << p[j].id << std::endl, it = 1;
                }
            }
            if (it == 0)
                std::cout << "Not Found" << std::endl;
        }
        else if (flag == "4")
        {
            for (int j = 0; j < n; j++)
            {
                if (p[j].publish == g[i])
                    std::cout << p[j].id << std::endl, it = 1;
            }
            if (it == 0)
                std::cout << "Not Found" << std::endl;
        }
        else if (flag == "5")
        {
            for (int j = 0; j < n; j++)
            {
                if (p[j].year == g[i])
                    std::cout << p[j].id << std::endl, it = 1;
            }
            if (it == 0)
                std::cout << "Not Found" << std::endl;
        }
    }
    return 0;
}
