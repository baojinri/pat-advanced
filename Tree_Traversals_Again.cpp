#include <iostream>
#include <string>
struct node
{
    int date;
    node *lchild, *rchild;
};

int a[30], b[30];
int count1 = 0, count2 = 0;
int stack[50];
int top = 0;

node *build(int m, int n)
{
    if (m == n - 1)
    {
        node *root = new node;
        root->date = b[m];
        root->lchild = NULL;
        root->rchild = NULL;
        return root;
    }
    int j;
    for (int i = 0; i < count1; i++)
    {
        for (j = m; j < n; j++)
        {
            if (b[j] == a[i])
            {
                break;
            }
        }
        if (j < n)
            break;
    }
    node *root = new node;
    root->date = b[j];
    if (m == j)
        root->lchild = NULL;
    else
    {
        root->lchild = build(m, j);
    }
    if (j + 1 == n)
        root->rchild = NULL;
    else
    {
        root->rchild = build(j + 1, n);
    }
    return root;
}

int postorder(node *root)
{
    if (root->lchild != NULL)
        postorder(root->lchild);
    if (root->rchild != NULL)
        postorder(root->rchild);
    std::cout << root->date << " ";
    return 0;
}

int main()
{
    int n;
    std::cin >> n;
    n = n * 2;
    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;
        if (s == "Push")
        {
            std::cin >> stack[top++];
            a[count1++] = stack[top - 1];
        }
        else
        {
            b[count2++] = stack[--top];
        }
    }
    node *root = new node;
    root = build(0, count2);
    if (root->lchild != NULL)
        postorder(root->lchild);
    if (root->rchild != NULL)
        postorder(root->rchild);
    std::cout << root->date;

    return 0;
}