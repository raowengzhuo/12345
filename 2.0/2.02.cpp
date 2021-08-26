//牛客-链表是否有环
bool hasCycle(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }
    struct ListNode *before = head;
    struct ListNode *cur = head->next;
    struct ListNode *pre;
    before->next = NULL;
    while (cur)
    {
        pre = cur->next;
        cur->next = before;
        before = cur;
        cur = pre;
    }
    if (before == head)
    {
        return true;
    }
    return false;
}
