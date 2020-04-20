#include <iostream>
struct BiTnode
{
    int date;
    struct BiTnode *lchild, *rchild;
};
int n, a[30], b[30];
struct quene
{
    BiTnode *q[30];
    int h, r;
};

bool isempty(quene q)
{
    if (q.h == q.r)
        return true;
    else
        return false;
}

int enquene(quene &q, BiTnode *p)
{
    q.h++;
    q.q[q.h] = p;
    return 0;
}

BiTnode *dequene(quene &q)
{
    return q.q[++q.r];
}

int levelorder(BiTnode *root)
{
    quene q;
    q.h = -1;
    q.r = -1;
    if (root != NULL)
    {
        std::cout << root->date;
        if (root->lchild != NULL)
            enquene(q, root->lchild);
        if (root->rchild != NULL)
            enquene(q, root->rchild);
    }
    while (!isempty(q))
    {
        BiTnode *p = dequene(q);
        if (p->lchild != NULL)
            enquene(q, p->lchild);
        if (p->rchild != NULL)
            enquene(q, p->rchild);
        std::cout << " " << p->date;
    }
    return 0;
}

BiTnode *build(int a[], int b[], int p, int q)
{
    if (p == q - 1)
    {
        BiTnode *bi = new BiTnode;
        bi->date = b[p];
        bi->lchild = NULL;
        bi->rchild = NULL;
        return bi;
    }
    int j;
    for (int i = n-1; i > -1; i--)
    {
        for (j = p; j < q; j++)
        {
            if (a[i] == b[j])
            {
                break;
            }
        }
        if (j < q)
            break;
    }
    BiTnode *bi = new BiTnode;
    bi->date = b[j];
    if (p < j)
        bi->lchild = build(a, b, p, j);
    else
        bi->lchild = NULL;
    if (j + 1 < q)
        bi->rchild = build(a, b, j + 1, q);
    else
        bi->rchild = NULL;
    return bi;
}

int main()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> b[i];
    }
    BiTnode *root = new BiTnode;
    root = build(a, b, 0, n);
    levelorder(root);
    return 0;
}