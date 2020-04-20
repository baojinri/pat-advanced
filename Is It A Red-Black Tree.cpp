#include <algorithm>
#include <cmath>
#include <iostream>
struct node
{
    int date;
    node *l, *r;
};
int a[50];
int b[50];
int sum = -1;
int flag = 0;

bool cmp(int a, int b)
{
    return abs(a) < abs(b);
}

node *build(int p, int q, int n)
{
    if (p + 1 == q)
    {
        node *root = new node;
        root->date = b[p];
        root->l = NULL;
        root->r = NULL;
        return root;
    }
    int temp;
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = p; j < q; j++)
        {
            if (a[i] == b[j])
            {
                temp = j;
                break;
            }
        }
        if (j < q)
            break;
    }
    node *root = new node;
    root->date = b[temp];
    if (p < temp)
        root->l = build(p, temp, n);
    else
        root->l = NULL;
    if (temp + 1 < q)
        root->r = build(temp + 1, q, n);
    else
        root->r = NULL;

    return root;
}

int judge(node *root, int n)
{
    if (flag == 1)
        return 0;
    if (root->date > 0)
        n++;
    if (root->l == NULL && root->r == NULL)
    {
        if (sum == -1)
            sum = n;
        else if (sum != n)
            flag = 1;
        return 0;
    }
    if (root->l != NULL)
    {
        if (root->date < 0 && root->l->date < 0)
            flag = 1;
        judge(root->l, n);
    }
    if (root->r != NULL)
    {
        if (root->date < 0 && root->r->date < 0)
            flag = 1;
        judge(root->r, n);
    }
    return 0;
}

int main()
{
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++)
    {
        int temp;
        std::cin >> temp;
        for (int j = 0; j < temp; j++)
        {
            std::cin >> a[j];
            b[j] = a[j];
        }
        std::sort(b, b + temp, cmp);
        node *root = build(0, temp, temp);
        flag = 0;
        sum = -1;
        if (root->date < 0)
            std::cout << "No" << std::endl;
        else
        {
            judge(root, 0);
            if (flag == 1)
                std::cout << "No" << std::endl;
            else
                std::cout << "Yes" << std::endl;
        }
    }
    return 0;
}