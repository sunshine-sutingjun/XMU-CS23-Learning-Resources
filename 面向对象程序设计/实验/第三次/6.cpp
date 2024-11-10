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

ListNode *middleNode(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    ListNode *head;
    head = createList();
    ListNode *ans = middleNode(head);

    if (ans == NULL)
    {
        cout << "-1";
    }
    else
    {
        while (ans != NULL)
        {
            cout << ans->val << " ";
            ans = ans->next;
        }
    }
    return 0;
}