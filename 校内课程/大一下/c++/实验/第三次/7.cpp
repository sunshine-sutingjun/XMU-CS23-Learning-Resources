#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *createList()
{
    ListNode *head = NULL;
    ListNode *p1, *p2;
    p1 = new ListNode;
    p2 = p1;
    cin >> p1->val;
    while (p1->val != -1)
    {
        if (head == NULL)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
        p1 = new ListNode;
        cin >> p1->val;
    }
    p2->next = NULL;
    delete p1;
    return head;
}

ListNode *mergeNodes(ListNode *head)
{
    ListNode dummy;
    ListNode *tail = &dummy;
    int sum = 0;
    for (ListNode *p = head->next; p != NULL; p = p->next)
    {
        if (p->val == 0)
        {
            if (sum > 0)
            {
                tail->next = new ListNode;
                tail->next->val = sum;
                tail = tail->next;
            }
            sum = 0;
        }
        else
        {
            sum += p->val;
        }
    }
    tail->next = NULL;
    return dummy.next;
}

int main()
{
    ListNode *head;
    head = createList();
    ListNode *ans = mergeNodes(head);

    while (ans != NULL)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}