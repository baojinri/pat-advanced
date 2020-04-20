#include <algorithm>
#include <iostream>
struct student
{
    int id;
    int rank;
    int ge, gi;
    int choice[5];
};
student s[40010];
struct school
{
    int rank;
    int student[40000];
    int count = 0;
};
school g[100];

int numbre[100];

bool cmp(student a, student b)
{
    if (a.ge + a.gi == b.ge + b.gi)
    {
        return a.ge > b.ge;
    }
    return a.ge + a.gi > b.ge + b.gi;
}

int main()
{
    int n, m, k;
    std::cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        std::cin >> numbre[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> s[i].ge >> s[i].gi;
        for (int j = 0; j < k; j++)
        {
            std::cin >> s[i].choice[j];
        }
        s[i].id = i;
    }
    std::sort(s, s + n, cmp);
    s[0].rank = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i].ge == s[i - 1].ge && s[i].gi == s[i - 1].gi)
        {
            s[i].rank = s[i - 1].rank;
        }
        else
        {
            s[i].rank = i + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int temp = s[i].choice[j];
            if (numbre[temp] > g[temp].count || s[i].rank == g[temp].rank)
            {
                g[temp].student[g[temp].count] = s[i].id;
                g[temp].count++;
                g[temp].rank = s[i].rank;
                break;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        std::sort(g[i].student, g[i].student + g[i].count);
        for (int j = 0; j < g[i].count - 1; j++)
        {
            std::cout << g[i].student[j] << " ";
        }
        if (g[i].count == 0)
        {
            std::cout << std::endl;
        }
        else
        {
            std::cout << g[i].student[g[i].count - 1] << std::endl;
        }
    }
    return 0;
}