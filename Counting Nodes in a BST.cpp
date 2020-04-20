#include <iostream>
struct node
{
    int date;
    node *l, *r;
};
int max = 0;
int sum1 = 0, sum2 = 0;

int order(node *root, int deep)
{
    if (deep > max)
    {
        max = deep;
    }
    if (root->l != NULL)
        order(root->l, deep + 1);
    if (root->r != NULL)
        order(root->r, deep + 1);
    return 0;
}

int preorder(node *root, int deep)
{
    if (deep == max)
        sum1++;
    if (deep == max - 1)
        sum2++;
    if (root->l != NULL)
        preorder(root->l, deep + 1);
    if (root->r != NULL)
        preorder(root->r, deep + 1);
    return 0;
}

int main()
{
    int n;
    std::cin >> n;
    int x;
    std::cin >> x;
    node *root = new node;
    root->date = x;
    root->l = NULL;
    root->r = NULL;
    node *p = new node;
    for (int i = 1; i < n; i++)
    {
        int y;
        std::cin >> y;
        p = root;
        while (p != NULL)
        {
            if (y <= p->date && p->l != NULL)
            {
                p = p->l;
            }
            else if (y <= p->date && p->l == NULL)
            {
                node *q = new node;
                q->date = y;
                p->l = q;
                q->l = NULL;
                q->r = NULL;
                break;
            }
            else if (y > p->date && p->r != NULL)
            {
                p = p->r;
            }
            else
            {
                node *q = new node;
                q->date = y;
                p->r = q;
                q->l = NULL;
                q->r = NULL;
                break;
            }
        }
    }
    order(root, 0);
    preorder(root, 0);
    std::cout << sum1 << " + " << sum2 << " = " << sum1 + sum2;
    return 0;
}