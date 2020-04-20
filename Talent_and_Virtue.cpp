#include <algorithm>
#include <iostream>
#include <string>
struct person
{
    std::string name;
    int virtue, talent;
};
person s[100010];
int count = 0;
int h;

bool cmp(person a, person b)
{
    if (a.virtue >= h && b.virtue >= h)
    {
        if (a.talent >= h && b.talent >= h)
        {
            if (a.talent + a.virtue == b.virtue + b.talent && a.virtue == b.virtue)
                return a.name < b.name;
            else if (a.talent + a.virtue == b.virtue + b.talent)
                return a.virtue > b.virtue;
            return a.talent + a.virtue > b.virtue + b.talent;
        }
        else if (a.talent < h && b.talent < h)
        {
            if (a.talent + a.virtue == b.virtue + b.talent && a.virtue == b.virtue)
                return a.name < b.name;
            else if (a.talent + a.virtue == b.virtue + b.talent)
                return a.virtue > b.virtue;
            return a.talent + a.virtue > b.virtue + b.talent;
        }
        return a.talent >= h;
    }
    else if (a.virtue < h && b.virtue < h)
    {
        if (a.virtue >= a.talent && b.virtue >= b.talent)
        {
            if (a.virtue == b.virtue)
                return a.name < b.name;
            return a.virtue > b.virtue;
        }
        else if (a.virtue < a.talent && b.virtue < b.talent)
        {
            if (a.virtue == b.virtue)
                return a.name < b.name;
            return a.virtue > b.virtue;
        }
        return a.virtue >= a.talent;
    }
    return a.virtue >= h;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n, l;
    std::cin >> n >> l >> h;
    for (int i = 0; i < n; i++)
    {
        std::string name;
        int v, t;
        std::cin >> name >> v >> t;
        if (v >= l && t >= l)
        {
            s[count].name = name;
            s[count].virtue = v;
            s[count].talent = t;
            count++;
        }
    }
    std::sort(s, s + count, cmp);
    std::cout << count << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout << s[i].name << " " << s[i].virtue << " " << s[i].talent << std::endl;
    }

    return 0;
}