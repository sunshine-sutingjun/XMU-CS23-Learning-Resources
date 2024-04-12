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

int main()
{
    node *head = NULL;
    head = createList(); // 创建链表

    if (head == NULL)
    { // 如果链表为空，则直接输出-1
        cout << "-1 ";
    }
    else
    { // 否则，遍历链表并输出每个节点的值
        node *p = head;
        while (p != NULL)
        {
            cout << p->val << " ";
            p = p->next; // 移动到下一个节点
        }
    }

    return 0;
}