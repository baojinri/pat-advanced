#include <algorithm>
#include <iostream>
#include <string>
struct person
{
    std::string name;
    int age;
    int weathy;
};
person p[100010];
bool cmp(person a, person b)
{
    if (a.weathy == b.weathy)
    {
        if (a.age == b.age)
        {
            return a.name < b.name;
        }
        return a.age < b.age;
    }
    return a.weathy > b.weathy;
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i].name >> p[i].age >> p[i].weathy;
    }
    std::sort(p, p + n, cmp);
    for (int i = 0; i < k; i++)
    {
        int temp, count = 0, agef, ager;
        std::cin >> temp >> agef >> ager;
        std::cout << "Case #" << i + 1 << ":" << std::endl;
        for (int j = 0; j < n; j++)
        {
            if (p[j].age >= agef && p[j].age <= ager)
            {
                std::cout << p[j].name << " " << p[j].age << " " << p[j].weathy << std::endl;
                count++;
                if (count == temp)
                    break;
            }
        }
        if (count == 0)
        {
            std::cout << "None" << std::endl;
        }
    }

    return 0;
}