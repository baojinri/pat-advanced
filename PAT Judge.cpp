#include <algorithm>
#include <iostream>
struct node
{
    int name;
    int rank;
    int grade[5] = {-2, -2, -2, -2, -2};
    int total = 0;
    int sum = 0;
} s[10010];
int c[5];

bool cmp(node a, node b)
{
    if (a.total == b.total && a.sum == b.sum)
        return a.name < b.name;
    if (a.total == b.total)
        return a.sum > b.sum;
    return a.total > b.total;
}

int main()
{
    int n, k, m;
    std::cin >> n >> k >> m;
    for (int i = 0; i < k; i++)
    {
        std::cin >> c[i];
    }
    for (int i = 0; i < m; i++)
    {
        int id, num, grade;
        std::cin >> id >> num >> grade;
        s[id].name = id;
        if (grade > s[id].grade[num - 1])
        {
            s[id].grade[num - 1] = grade;
        }
    }
    for (int i = 0; i < 10010; i++)
    {
        s[i].name = i;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (s[i].grade[j] > 0)
            {
                s[i].total += s[i].grade[j];
                if (s[i].grade[j] == c[j])
                    s[i].sum++;
            }
        }
    }
    std::sort(s + 1, s + n + 1, cmp);
    int j;
    for (j = 1; j < n + 1; j++)
    {
        if (s[j].total == 0&&s[j].grade[0]!=0&&s[j].grade[1]!=0&&s[j].grade[2]!=0&&s[j].grade[3]!=0&&s[j].grade[4]!=0)
        {
            break;
        }
    }
    s[1].rank = 1;
    for (int i = 2; i < j; i++)
    {
        if (s[i].total == s[i - 1].total)
            s[i].rank = s[i - 1].rank;
        else
            s[i].rank = i;
    }
    for (int i = 1; i < j; i++)
    {
        printf("%d %05d %d ", s[i].rank, s[i].name, s[i].total);
        for (int p = 0; p < k; p++)
        {
            if (s[i].grade[p] == -2)
                std::cout << "-";
            else if (s[i].grade[p] == -1)
                std::cout << 0;
            else
                std::cout << s[i].grade[p];
            if (p == k - 1)
                std::cout << std::endl;
            else
                std::cout << " ";
        }
    }

    return 0;
}