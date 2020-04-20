#include <iostream>
struct bnode
{
    int date;
    bnode *lchild, *rchild;
};

int a[1010];
int b[1010];
int flag = 0;
using std::cin;
using std::cout;

int preorder(bnode *root)
{
    b[flag] = root->date;
    flag++;
    if (root->lchild != NULL)
    {
        preorder(root->lchild);
    }
    if (root->rchild != NULL)
        preorder(root->rchild);

    return 0;
}

int mpreorder(bnode *root)
{
    b[flag] = root->date;
    flag++;
    if (root->rchild != NULL)
        mpreorder(root->rchild);
    if (root->lchild != NULL)
    {
        mpreorder(root->lchild);
    }
    return 0;
}

int postorder(bnode *root)
{
    if (root->lchild != NULL)
    {
        postorder(root->lchild);
    }
    if (root->rchild != NULL)
        postorder(root->rchild);
    cout << root->date << " ";
    return 0;
}

int mpostorder(bnode *root)
{
    if (root->rchild != NULL)
        mpostorder(root->rchild);
    if (root->lchild != NULL)
    {
        mpostorder(root->lchild);
    }
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
    bnode *root = new bnode;
    root->date = a[0];
    root->lchild = NULL;
    root->rchild = NULL;
    for (int i = 1; i < n; i++)
    {
        bnode *b = new bnode;
        bnode *p = root;
        b->date = a[i];
        b->lchild = NULL;
        b->rchild = NULL;
        while (true)
        {
            if (b->date < p->date)
            {
                if (p->lchild == NULL)
                {
                    p->lchild = b;
                    break;
                }
                else
                {
                    p = p->lchild;
                }
            }
            else
            {
                if (p->rchild == NULL)
                {
                    p->rchild = b;
                    break;
                }
                else
                {
                    p = p->rchild;
                }
            }
        }
    }
    preorder(root);
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            break;
    }
    if (i == n)
    {
        cout << "YES" << std::endl;
        if (root->lchild != NULL)
        {
            postorder(root->lchild);
        }
        if (root->rchild != NULL)
            postorder(root->rchild);
        cout << root->date;
        return 0;
    }
    flag = 0;
    mpreorder(root);
    for (i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            break;
    }
    if (i == n)
    {
        cout << "YES" << std::endl;
        if (root->rchild != NULL)
            mpostorder(root->rchild);
        if (root->lchild != NULL)
        {
            mpostorder(root->lchild);
        }
        cout << root->date;
        return 0;
    }
    cout << "NO";
}