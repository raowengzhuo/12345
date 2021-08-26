//删除链表元素
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} LinkList;
//创建一个链表
LinkList *Creatlist_L(LinkList *L, int n)
{
    LinkList *p, *h;
    L = (LinkList *)malloc(sizeof(LinkList));
    L->next = NULL;
    h = L;
    for (int i = 0; i < n; i++)
    {
        p = (LinkList *)malloc(sizeof(LinkList));
        scanf("%d", &p->data);
        p->next = h->next;
        h->next = p;
    }
    return L;
}
//删除指定的元素
LinkList *deletenode(LinkList *head, int m)
{
    LinkList *p, *q, *s;
    p = head;
    q = head->next;
    while (q)
    {
        if (q->data == m)
        {
            p->next = q->next;
            s = q;
            q = q->next;
            free(s);
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
    return head;
}
//输出链表
void printlist(LinkList *head)
{
    LinkList *p;
    p = head->next;
    if (!p)
    {
        printf("The link is NULL!");
        exit(0);
    }
    while (p)
    {
        printf("%d", p->data);
        p = p->next;
    }
}
int main()
{
    LinkList *head, *head1;
    int n = 0, num = 0;
    printf("请输入链表的长度：");
    scanf("%d", &n);

    head = Creatlist_L(head, n);
    printf("链表创立成功！");
    printf("\n");
    printf("输入要删除的元素：");
    scanf("%d", &num);
    printf("\n");
    head = deletenode(head, num);
    printlist(head);
}