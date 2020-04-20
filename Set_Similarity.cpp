#include <iomanip>
#include <iostream>
#include <set>
std::set<int> s[60];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
        {
            int temp;
            scanf("%d", &temp);
            s[i].insert(temp);
        }
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        int p, q;
        scanf("%d %d", &p, &q);
        std::set<int> temp;
        temp = s[p - 1];
        for (std::set<int>::iterator it = s[q - 1].begin(); it != s[q - 1].end(); it++)
        {
            temp.insert(*it);
        }
        double sum1 = temp.size();
        double sum2 = s[p - 1].size() + s[q - 1].size() - sum1;
        double ans = sum2 / sum1 * 100;
        printf("%0.1f\%\n", ans);
    }

    return 0;
}