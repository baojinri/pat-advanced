#include<iostream>
#include<algorithm>
#include<string>
struct list
{
    int date;
    int next;
};
list l[1000000];
list g[1000000];
int count = 0;

bool cmp(list a,list b)
{
    return a.date < b.date;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n, begin;
    std::cin >> n >> begin;
    for (int i = 0; i < n; i++)
    {
        int adress;
        std::cin >> adress;
        std::cin >> l[adress].date >> l[adress].next;
    }
    while (begin!=-1)
    {
        g[count].date = l[begin].date;
        g[count].next = begin;
        count++;
        begin = l[begin].next;
    }
    std::sort(g, g + count, cmp);
    std::cout << count<<" ";
    for (int i = 0; i < count; i++)
    {
        std::string s = std::to_string(g[i].next);
        for (int j = s.size(); j < 5; j++)
        {
            s = "0" + s;
        }

        std::cout << s << std::endl
                  << s << " " << g[i].date << " ";
    }
    std::cout << -1;


    return 0;
}