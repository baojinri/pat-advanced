#include <algorithm>
#include <iostream>
#include <string>
struct student
{
    double grade;
    std::string school;
};
student s[100010];
struct school
{
    int rank;
    double grade = 0;
    int number = 0;
    std::string name;
};
school sc[100000];
int count = 0;

bool cmp(student a, student b)
{
    return a.school < b.school;
}
bool cmp1(school a, school b)
{
    if (a.grade == b.grade && a.number == b.number)
        return a.name < b.name;
    if (a.grade == b.grade)
        return a.number < b.number;
    return a.grade > b.grade;
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::string s1, s2;
        double g;
        std::cin >> s1 >> g >> s2;
        if (s1[0] == 'B')
            g = g / 1.5;
        else if (s1[0] == 'T')
            g = g * 1.5;
        for (int j = 0; j < s2.size(); j++)
        {
            if (s2[j] >= 'A' && s2[j] <= 'Z')
                s2[j] += 32;
        }
        s[i].grade = g;
        s[i].school = s2;
    }
    std::sort(s, s + n, cmp);
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i].school != s[p].school)
        {
            count++;
            p = i;
        }
        sc[count].grade += s[i].grade;
        sc[count].name = s[i].school;
        sc[count].number++;
    }
    for (int i = 0; i < count + 1; i++)
    {
        sc[i].grade = int(sc[i].grade);
    }

    std::sort(sc, sc + count + 1, cmp1);
    sc[0].rank = 1;
    for (int i = 1; i < count + 1; i++)
    {
        if (sc[i].grade == sc[i - 1].grade)
            sc[i].rank = sc[i - 1].rank;
        else
            sc[i].rank = i + 1;
    }
    std::cout << count + 1 << std::endl;
    for (int i = 0; i < count + 1; i++)
    {
        std::cout << sc[i].rank << " " << sc[i].name << " " << sc[i].grade << " " << sc[i].number << std::endl;
    }

    return 0;
}