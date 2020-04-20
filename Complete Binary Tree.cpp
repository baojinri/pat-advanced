#include <iostream>
#include <string>
struct node
{
    int tag;
    int l, r;
};
node tree[25];
int count = 0;
int quene[25];
int f = 0, r = 0;

int order(int v)
{
    count++;
    if (tree[v].l != -1)
        order(tree[v].l);
    if (tree[v].r != -1)
        order(tree[v].r);
    return 0;
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        if (s1 == "-")
            tree[i].l = -1;
        else if (s1.size() == 1)
            tree[i].l = s1[0] - '0';
        else
            tree[i].l = (s1[0] - '0') * 10 + s1[1] - '0';
        if (s2 == "-")
            tree[i].r = -1;
        else if (s2.size() == 1)
            tree[i].r = s2[0] - '0';
        else
            tree[i].r = (s2[0] - '0') * 10 + s2[1] - '0';
    }
    int root = 0;
    for (int i = 0; i < n; i++)
    {
        order(i);
        if (count == n)
        {
            root = i;
            break;
        }
        count = 0;
    }
    quene[r++] = root;
    while (r != f)
    {
        int temp = quene[f++];
        tree[temp].tag = f - 1;
        if (tree[temp].l != -1)
            quene[r++] = tree[temp].l;
        if (tree[temp].r != -1)
            quene[r++] = tree[temp].r;
    }
    int i;
    for (i = 0; i < n; i++)
    {
        if (tree[i].l != -1)
        {
            if (tree[tree[i].l].tag != tree[i].tag * 2 + 1)
                break;
        }
        if (tree[i].r != -1)
        {
            if (tree[tree[i].r].tag != tree[i].tag * 2 + 2)
                break;
        }
    }
    if (i == n)
    {
        std::cout << "YES"
                  << " " << quene[n - 1];
    }
    else
    {
        std::cout << "NO"
                  << " " << root;
    }
    return 0;
}