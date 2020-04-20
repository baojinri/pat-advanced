#include <algorithm>
#include <iostream>
#include <string>
struct textee
{
    std::string name;
    int scroe;
    int finrank, localnum, localrank;
};
textee text[30010];

bool cmp(textee a, textee b)
{
    if (a.scroe == b.scroe)
        return a.name < b.name;
    return a.scroe > b.scroe;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        for (int j = p; j < p + temp; j++)
        {
            std::cin >> text[j].name >> text[j].scroe;
            text[j].localnum = i + 1;
        }
        std::sort(text + p, text + p + temp, cmp);
        text[p].localrank = 1;
        for (int j = p + 1; j < p + temp; j++)
        {
            if (text[j].scroe == text[j - 1].scroe)
                text[j].localrank = text[j - 1].localrank;
            else
                text[j].localrank = j - p + 1;
        }
        p = p + temp;
    }
    std::sort(text, text + p, cmp);
    text[0].finrank = 1;
    for (int i = 1; i < p; i++)
    {
        if (text[i].scroe == text[i - 1].scroe)
            text[i].finrank = text[i - 1].finrank;
        else
            text[i].finrank = i + 1;
    }
    std::cout << p << std::endl;
    for (int i = 0; i < p; i++)
    {
        std::cout << text[i].name << " "
                  << text[i].finrank << " "
                  << text[i].localnum << " "
                  << text[i].localrank << std::endl;
    }
    return 0;
}