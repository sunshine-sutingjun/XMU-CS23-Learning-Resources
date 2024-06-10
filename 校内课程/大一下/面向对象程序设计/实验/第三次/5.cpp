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
        p1 = new struct ListNode;
        cin >> p1->val;
    }
    p2->next = NULL;
    delete p1;
    return head;
}

ListNode *getKthFromEnd(ListNode *head, int k) // 注意，这里不管是从前往后还是从后往前都是从0开始数数
{
    ListNode *fast = head, *slow = head;
    for (int i = 0; i <= k; ++i)
    {
        if (fast == NULL)
            return NULL; // k超过链表长度
        fast = fast->next;
    }
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main()
{
    ListNode *head;
    int k;
    head = createList();
    cin >> k;
    ListNode *ans = getKthFromEnd(head, k);
    if (ans == NULL)
        cout << "-1";
    else
        cout << ans->val;
    return 0;
}