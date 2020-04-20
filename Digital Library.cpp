#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
struct node
{
    std::string id, title, author, pu, year;
    std::vector<std::string> key;
} book[10010];

bool cmp(node a, node b)
{
    return a.id < b.id;
}

int main()
{
    int n;
    std::cin >> n;
    getchar();
    for (int i = 0; i < n; i++)
    {
        std::getline(std::cin, book[i].id);
        std::getline(std::cin, book[i].title);
        std::getline(std::cin, book[i].author);
        std::string t, temp;
        std::getline(std::cin, t);
        for (int j = 0; j < t.size(); j++)
        {
            if (t[j] == ' ')
            {
                book[i].key.push_back(temp);
                temp = "";
            }
            else
            {
                temp += t[j];
            }
        }
        book[i].key.push_back(temp);
        std::getline(std::cin, book[i].pu);
        std::getline(std::cin, book[i].year);
    }
    std::sort(book, book + n, cmp);
    int k;
    std::cin >> k;
    getchar();
    for (int i = 0; i < k; i++)
    {
        std::string s;
        std::getline(std::cin, s);
        int temp = s[0] - '0';
        std::cout << s << std::endl;
        s.erase(s.begin(), s.begin() + 3);
        int count = 0;
        if (temp == 1)
        {
            for (int j = 0; j < n; j++)
            {
                if (book[j].title == s)
                {
                    std::cout << book[j].id << std::endl;
                    count++;
                }
            }
            if (count == 0)
                std::cout << "Not Found" << std::endl;
        }
        else if (temp == 2)
        {
            for (int j = 0; j < n; j++)
            {
                if (book[j].author == s)
                {
                    std::cout << book[j].id << std::endl;
                    count++;
                }
            }
            if (count == 0)
                std::cout << "Not Found" << std::endl;
        }
        else if (temp == 3)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < book[j].key.size(); k++)
                {
                    if (book[j].key[k] == s)
                    {
                        std::cout << book[j].id << std::endl;
                        count++;
                        break;
                    }
                }
            }
            if (count == 0)
                std::cout << "Not Found" << std::endl;
        }
        else if (temp == 4)
        {
            for (int j = 0; j < n; j++)
            {
                if (book[j].pu == s)
                {
                    std::cout << book[j].id << std::endl;
                    count++;
                }
            }
            if (count == 0)
                std::cout << "Not Found" << std::endl;
        }
        else if (temp == 5)
        {
            for (int j = 0; j < n; j++)
            {
                if (book[j].year == s)
                {
                    std::cout << book[j].id << std::endl;
                    count++;
                }
            }
            if (count == 0)
                std::cout << "Not Found" << std::endl;
        }
    }

    return 0;
}