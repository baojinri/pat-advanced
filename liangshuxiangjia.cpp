#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int jw = 0;
        ListNode h(0);
        ListNode *p = &h;
        while (l1 != NULL && l2 != NULL)
        {
            int temp = l1->val + l2->val + jw;
            if (temp > 9)
            {
                temp = temp - 10;
                jw = 1;
            }
            else
            {
                jw = 0;
            }
            ListNode *n = new ListNode(temp);
            p->next = n;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 != NULL)
        {
            while (l1 != NULL)
            {
                int temp = l1->val + jw;
                if (temp > 9)
                {
                    temp = temp - 10;
                    jw = 1;
                }
                else
                {
                    jw = 0;
                }
                
                ListNode *n = new ListNode(temp);
                p->next = n;
                p = p->next;
                l1 = l1->next;
            }
        }
        else if (l2 != NULL)
        {
            while (l2 != NULL)
            {
                int temp = l2->val + jw;
                if (temp > 9)
                {
                    temp = temp - 10;
                    jw = 1;
                }
                else
                {
                    jw = 0;
                }
                
                ListNode *n = new ListNode(temp);
                p->next = n;
                p = p->next;
                l2 = l2->next;
            }
        }
        if (jw == 1)
        {
            ListNode *n = new ListNode(1);
            p->next = n;
            p = p->next;
        }

        return (h.next);
    }
};

int main()
{
    int n, m;
    std::cin >> n >> m;
    ListNode h1(0), h2(0);
    ListNode *p = &h1;
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        ListNode *n = new ListNode(temp);
        p->next = n;
        p = p->next;
    }
    p = &h2;
    for (int i = 0; i < m; i++)
    {
        int temp;
        std::cin >> temp;
        ListNode *n = new ListNode(temp);
        p->next = n;
        p = p->next;
    }
    Solution a;
    ListNode *q = a.addTwoNumbers(h1.next, h2.next);
    while (q != NULL)
    {
        std::cout << q->val << " ";
        q = q->next;
    }
    return 0;
}
