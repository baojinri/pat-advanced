#include <iostream>
struct node
{
    int date;
    struct node *next;
};

int main()
{
    long long n, b;
    std::cin >> n >> b;
    node *h1 = new node;
    node *h2 = new node;
    h1->next = NULL, h2->next = NULL;
    node *h3 = h2;
    while (n > 0)
    {
        int temp = n % b;
        n = n / b;
        node *p = new node;
        node *q = new node;
        p->date = temp;
        q->date = temp;

        p->next = h1->next;
        h1->next = p;

        h3->next = q;
        q->next = NULL;
        h3 = q;
    }
    h3 = h1->next;
    h2 = h2->next;
    while (h2 != NULL)
    {
        if (h2->date != h3->date)
            break;
        h2 = h2->next;
        h3 = h3->next;
    }
    if (h2 != NULL)
    {
        std::cout << "No" << std::endl;
    }
    else
    {
        std::cout << "Yes" << std::endl;
    }
    h1 = h1->next;
    while (h1->next != NULL)
    {
        std::cout << h1->date << " ";
        h1 = h1->next;
    }
    std::cout << h1->date;
    return 0;
}