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
        node *newNode = new node; // 创建一个新节点
        newNode->val = num;       // 赋值
        newNode->next = NULL;     // 下一个节点指针为空
        if (head == NULL)
        { // 如果链表为空，新节点既是头节点也是尾节点
            head = newNode;
            tail = newNode;
        }
        else
        { // 否则，添加到链表末尾
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head; // 返回链表的头节点
}

node *merge(node *head1, node *head2)
{
    node dummy;          // 创建一个哑节点作为合并后链表的头部
    node *tail = &dummy; // 尾指针指向哑节点
    dummy.next = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->val < head2->val)
        {                        // 如果链表1的当前节点值小于链表2的
            tail->next = head1;  // 将链表1的当前节点添加到结果链表中
            head1 = head1->next; // 链表1向前移动
        }
        else
        {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next; // 更新结果链表的尾节点
    }
    // 如果其中一个链表已经为空，则将另一个链表的剩余部分添加到结果链表中
    if (head1 != NULL)
    {
        tail->next = head1;
    }
    else if (head2 != NULL)
    {
        tail->next = head2;
    }
    return dummy.next; // 返回哑节点的下一个节点，即合并后链表的头节点
}

int main()
{
    node *head1, *head2, *head3;

    head1 = createList();        // 创建第一个链表
    head2 = createList();        // 创建第二个链表
    head3 = merge(head1, head2); // 合并两个链表

    if (head3 == NULL)
    {
        cout << "-1 ";
    }
    else
    {
        node *p = head3;
        while (p != NULL)
        { // 遍历合并后的链表，输出每个节点的值
            cout << p->val << " ";
            p = p->next;
        }
    }

    return 0;
}