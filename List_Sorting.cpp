#include <iostream>
#include <string>
#include<algorithm>

struct record
{
    std::string s[3];
};
record students[100010];
int n, c;

bool cmp(record a,record b)
{
    if(a.s[c-1]==b.s[c-1])
        return a.s[0] < b.s[0];
    return a.s[c - 1] < b.s[c - 1];
}

int main()
{
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %s",students[i].s[0].c_str(),students[i].s[1].c_str(),students[i].s[2].c_str());
    }
    std::sort(students, students + n, cmp);
    for (int i = 0; i < n; i++)
    {
        printf("%s %s %s\n", students[i].s[0].c_str(), students[i].s[1].c_str(), students[i].s[2].c_str());
    }
    
    return 0;
}
/* #include <iostream>
#include <string>
#include<algorithm>

struct record
{
    std::string s[3];
};
record students[100010];
int n, c;

bool cmp(record a,record b)
{
    if(a.s[c-1]==b.s[c-1])
        return a.s[0] < b.s[0];
    return a.s[c - 1] < b.s[c - 1];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        std::cin >> students[i].s[0] >> students[i].s[1] >> students[i].s[2];
    }
    std::sort(students, students + n, cmp);
    for (int i = 0; i < n; i++)
    {
        std::cout << students[i].s[0] << " " << students[i].s[1] << " " << students[i].s[2] << std::endl;
    }
    
    return 0;
} */