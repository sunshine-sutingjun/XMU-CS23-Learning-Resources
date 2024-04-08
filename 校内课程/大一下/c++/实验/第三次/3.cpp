#include <iostream>

using namespace std;

struct node
{
    int val;
    node *next;
};

node *createList()
{
    int num;
    node *head = NULL, *tail = NULL;
    while (cin >> num && num != -1)
    {
        node *newNode = new node;
        newNode->val = num;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

node *deleteElements(node *head, int v)
{
    // 删除头部为v的节点
    while (head != NULL && head->val == v)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }

    if (head == NULL)
    {
        return NULL;
    }

    // 删除非头部为v的节点
    node *current = head;
    while (current->next != NULL)
    {
        if (current->next->val == v)
        {
            node *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else
        {
            current = current->next;
        }
    }
    return head;
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