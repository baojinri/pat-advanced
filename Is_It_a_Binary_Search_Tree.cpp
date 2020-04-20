#include <iostream>
struct bnode
{
    int date;
    bnode *lchild, *rchild;
};

int a[1010];
int flag = 0;
using std::cin;
using std::cout;

bnode *build(int p, int q)
{
    if (p == q - 1)
    {
        bnode *b = new bnode;
        b->date = a[p];
        b->lchild = NULL;
        b->rchild = NULL;
        return b;
    }
    int temp = a[p];
    int j;
    for (int i = p + 1; i < q; i++)
    {
        if (a[i] >= temp)
        {
            j = i;
            break;
        }
    }
    for (int i = j; i < q; i++)
    {
        if (a[i] < temp)
        {
            flag = 1;
            return NULL;
        }
    }
    bnode *b = new bnode;
    b->date = a[p];
    if (p + 1 == j)
        b->lchild = NULL;
    else
        b->lchild = build(p + 1, j);

    if (j == q)
        b->rchild = NULL;
    else
        b->rchild = build(j, q);

    return b;
}

bnode *build1(int p, int q)
{
    if (p == q - 1)
    {
        bnode *b = new bnode;
        b->date = a[p];
        b->lchild = NULL;
        b->rchild = NULL;
        return b;
    }
    int temp = a[p];
    int j;
    for (int i = p + 1; i < q; i++)
    {
        if (a[i] < temp)
        {
            j = i;
            break;
        }
    }
    for (int i = j; i < q; i++)
    {
        if (a[i] >= temp)
        {
            flag = 1;
            return NULL;
        }
    }
    bnode *b = new bnode;
    b->date = a[p];
    if (p + 1 == j)
        b->lchild = NULL;
    else
        b->lchild = build1(p + 1, j);

    if (j == q)
        b->rchild = NULL;
    else
        b->rchild = build1(j, q);

    return b;
}

int postorder(bnode *root)
{
    if (root->lchild != NULL)
        postorder(root->lchild);
    if (root->rchild != NULL)
        postorder(root->rchild);
    cout << root->date << " ";
    return 0;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bnode *root = build(0, n);
    if (flag == 0)
    {
        cout << "YES" << std::endl;
        if (root->lchild != NULL)
            postorder(root->lchild);
        if (root->rchild != NULL)
            postorder(root->rchild);
        cout << root->date;
        return 0;
    }
    flag = 0;
    root = build1(0, n);
    if(flag==0)
    {
        cout << "YES" << std::endl;
        if (root->lchild != NULL)
            postorder(root->lchild);
        if (root->rchild != NULL)
            postorder(root->rchild);
        cout << root->date;
        return 0;
    }
    cout << "NO";
    return 0;
}