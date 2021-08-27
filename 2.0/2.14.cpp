//分割链表
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *creat() //指针函数
{
    struct ListNode *head, *p1, *p2;
    p1 = p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    char c;
    scanf("%d", &p1->val);
    head = NULL;
    int n = 0;
    while (p1->val != 0) //编号为0，输入结束
    {
        n = n + 1;
        if (n == 1)
            head = p1; //第一个，置头指针
        else
            p2->next = p1; //新开结点接上
        p2 = p1;
        p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
        scanf("%d", &p1->val);

    } //p1指向新开结点，p2指向最后结点
    p2->next = NULL;
    return (head);
}
void print(struct ListNode *head)
{
    struct ListNode *p = head;
    while (p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}
struct ListNode *partition(struct ListNode *head, int x)
{
    //保留相对位置
    typedef struct ListNode list;
    list *l1,*l2;
    l1 = (list *)malloc(sizeof(list));
    l1->next = NULL;
    list *head1 = l1;
    l2 = (list *)malloc(sizeof(list));
    l2->next = NULL;
    list *head2 = l2;
    if (head == NULL) //保证至少有两个结点
    {
        return head;
    }
    while (head)
    {
        if (head->val < x)
        { //尾插l1
            l1->next = head;
            l1 = l1->next; //因为head一定不为null，所以l1一定不为null,同理l2
        }
        else
        { //尾插l2
            l2->next = head;
            l2 = l2->next;
        }
        head = head->next;
    }
    l1->next = head2->next; //接链
    head2->next = NULL;
    l2->next = NULL;
    return head1->next;
}

int main()
{
    struct ListNode *p;
    int v;
    p = creat();
    scanf("%d", &v);
    p = partition(p, v);
    print(p);
    return 0;
}
