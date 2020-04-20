#include <algorithm>
#include <iostream>
struct node
{
    int date;
    int l, r;
};
node t[110];
int order1[110], count1 = 0, count = 0;
int a[110];
int quene[110];
int f = 0, r = 0;

int order(int v)
{
    if (t[v].l != -1)
        order(t[v].l);
    order1[count1++] = v;
    if (t[v].r != -1)
        order(t[v].r);
    return 0;
}

int levelorder(int v)
{
    quene[r++] = v;
    while (f != r)
    {
        int temp = quene[f++];
        std::cout << t[temp].date;
        count++;
        if (count != count1)
            std::cout << " ";
        if (t[temp].l != -1)
            quene[r++] = t[temp].l;
        if (t[temp].r != -1)
            quene[r++] = t[temp].r;
    }

    return 0;
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> t[i].l >> t[i].r;
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    std::sort(a, a + n);
    order(0);
    for (int i = 0; i < n; i++)
    {
        t[order1[i]].date = a[i];
    }
    levelorder(0);
    return 0;
}