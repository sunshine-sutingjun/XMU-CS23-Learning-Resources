#include <iostream>

using namespace std;

struct node
{
    int val;
    node *next;
};

node *createList()
{
    node *dummy = new node;
    node *current = dummy;
    int x;
    while (cin >> x && x != -1)
    {
        node *newNode = new node;
        newNode->val = x;
        newNode->next = NULL;
        current->next = newNode;
        current = current->next;
    }
    return dummy->next;
}

node *deleteElements(node *head, int v)
{
    node *dummy = new node;
    dummy->next = head;
    for (node *pre = dummy, *cur = head; cur != NULL; cur = cur->next)
    {
        if (cur->val == v)
        {
            pre->next = cur->next;
        }
        else
        {
            pre = cur;
        }
    }
    return dummy->next;
}

int main()
{
    node *head = NULL;
    head = createList(); // 创建链表

    int v;
    cin >> v; // 读取需要删除的元素值

    head = deleteElements(head, v); // 删除链表中值为v的元素

    if (head == NULL)
    {
        cout << "-1 ";
    }
    else
    {
        node *p = head;
        while (p != NULL)
        {
            cout << p->val << " ";
            p = p->next;
        }
    }

    return 0;
}