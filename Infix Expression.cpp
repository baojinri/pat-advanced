#include <iostream>
#include <string>
struct node
{
    std::string date;
    int l, r;
};
node tree[30];
int sum = 0;

int order(int v)
{
    sum++;
    if (tree[v].l != -1)
    {
        order(tree[v].l);
    }
    if (tree[v].r != -1)
    {
        order(tree[v].r);
    }
    return 0;
}

int inorder(int root)
{
    if (tree[root].l != -1 || tree[root].r != -1)
    {
        std::cout << "(";
        if (tree[root].l != -1)
            inorder(tree[root].l);
        std::cout << tree[root].date;
        if (tree[root].r != -1)
            inorder(tree[root].r);
        std::cout << ")";
    }
    else
        std::cout << tree[root].date;
    return 0;
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> tree[i + 1].date >> tree[i + 1].l >> tree[i + 1].r;
    }
    int root;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        order(i + 1);
        if (sum == n)
        {
            root = i + 1;
            break;
        }
    }
    if (tree[root].l != -1)
        inorder(tree[root].l);
    std::cout << tree[root].date;
    if (tree[root].r != -1)
        inorder(tree[root].r);

    return 0;
}