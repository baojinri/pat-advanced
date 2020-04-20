#include<iostream>
#include<string>
#include<algorithm>
struct student
{
    std::string name, id;
    int grade;
};
student s[100000];

bool cmp(student a,student b)
{
    return a.grade > b.grade;
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> s[i].name >> s[i].id >> s[i].grade;
    }
    int g1,g2;
    std::cin >> g1 >> g2;
    int count = 0;
    std::sort(s, s + n, cmp);
    int i = 0;
    while (s[i].grade>g2)
    {
        i++;
    }
    while (s[i].grade>=g1&&i<n)
    {
        std::cout << s[i].name << " " << s[i].id << std::endl;
        count++;
        i++;
    }
    if(count==0)
        std::cout << "NONE";

    return 0;
}