ListNode *oddEvenList(ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    ListNode *odd = head, *even = head->next, *evenHead = even;

    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;   // 将奇数节点指向下一个奇数节点
        even->next = even->next->next; // 将偶数节点指向下一个偶数节点
        odd = odd->next;               // 移动到下一个奇数节点
        even = even->next;             // 移动到下一个偶数节点
    }

    odd->next = evenHead; // 将偶数链表的头节点连接到奇数链表的尾部

    return head;
}