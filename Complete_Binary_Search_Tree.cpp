#include <algorithm>
#include <iostream>
struct node
{
    int date;
    node *lchild, *rchild;
};
int a[1000];
node b[1000];
int c[1000];
int count = 0;
int d[1000];

int  preorder(node *root)
{
    
    if(root->lchild!=NULL)
        preorder(root->lchild);

    c[count] = root->date;
    count++;

    if(root->rchild!=NULL)
        preorder(root->rchild);

    return 0;
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    std::sort(a, a + n);
    b[0].date = 0;
    b[0].lchild = NULL;
    b[0].rchild = NULL;
    for (int i = 1; i < n; i++)
    {
        b[i].date = i;
        b[i].lchild = NULL;
        b[i].rchild = NULL;
        if(i%2==0)
        {
            b[(i - 1) / 2].rchild = &b[i];
        }
        else
        {
            b[(i - 1) / 2].lchild = &b[i];
        }
    }
    preorder(&b[0]);
    for (int i = 0; i < count; i++)
    {
        d[c[i]] = a[i];
    }
    std::cout << d[0];
    for (int i = 1; i < count; i++)
    {
        std::cout << " " << d[i];
    }
    
    return 0;
}
