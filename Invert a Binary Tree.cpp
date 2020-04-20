#include <iostream>
#include <string>
struct node
{
    int date;
    int l, r;
};
node tree[14];
int quene[15];
int f = 0, r = 0;
int n;
int count = 0;

int levelorder(int v)
{
    quene[r++] = v;
    while (f != r)
    {
        int temp = quene[f++];
        count++;
        std::cout << temp;
        if (count != n)
            std::cout << " ";
        else
            std::cout << std::endl;
        if (tree[temp].r != -1)
            quene[r++] = tree[temp].r;
        if (tree[temp].l != -1)
            quene[r++] = tree[temp].l;
    }
    return 0;
}

int inorder(int v)
{
    if (tree[v].r != -1)
        inorder(tree[v].r);
    count++;
    std::cout << v;
    if (count != n)
        std::cout << " ";
    else
        std::cout << std::endl;
    if (tree[v].l != -1)
        inorder(tree[v].l);
    return 0;
}

int order(int v)
{
    if (tree[v].r != -1)
        order(tree[v].r);
    count++;
    if (tree[v].l != -1)
        order(tree[v].l);
    return 0;
}

int main()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        if (s1 == "-")
            tree[i].l = -1;
        else
            tree[i].l = s1[0] - '0';
        if (s2 == "-")
            tree[i].r = -1;
        else
            tree[i].r = s2[0] - '0';
        tree[i].date = i;
    }
    int i;
    for (i = 0; i < n; i++)
    {
        order(i);
        if (count == n)
        {
            break;
        }
        count = 0;
    }
    count = 0;
    levelorder(i);
    count = 0;
    inorder(i);
    return 0;
}