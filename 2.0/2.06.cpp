//公共节点
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
typedef struct stu
{
    int num;
    struct stu *node;
} STU, *Ptrstu;

Ptrstu creat()
{
    Ptrstu head;
    head = (Ptrstu)malloc(sizeof(STU));
    if (!head)
        exit(0);
    head->num = 0;
    head->node = NULL;
    return head;
}

void link(Ptrstu head)
{
    int n;
    Ptrstu next, p;
    p = head;
    next = creat();
    printf("请输入当前链表元素");
    scanf("%d", &n);
    next->num = n;
    while (p->node != NULL)
        p = p->node;
    p->node = next;
}

void pin(Ptrstu head)
{
    Ptrstu p;
    p = head->node;
    while (p)
    {
        printf("%d\t", p->num);
        p = p->node;
    }
}

void seek(Ptrstu head1, Ptrstu head2)
{
    Ptrstu p2, p1;
    p1 = head1;
    p2 = head2;
    while (p1->node != NULL)
    {
        p2 = head2;
        p1 = p1->node;
        while (p2->node != NULL)
        {
            p2 = p2->node;
            if (p1 == p2)
                break;
        }
        if (p1 == p2)
            break;
    }
    printf("相同节点的元素如下：\n");
    while (p2->node != NULL)
    {
        printf("%d ", p2->num);
        p2 = p2->node;
    }
    printf("%d ", p2->num);
}
int main()
{
    Ptrstu head1 = creat();
    Ptrstu head2 = creat();
    int i;
    int n;
    printf("请输入链表元素个数");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        link(head1);
    printf("第1个链表当前元素如下\n");
    pin(head1);

    printf("\n\n");
    int m;
    printf("请输入另一个链表元素个数（>4）");
    scanf("%d", &m);
    for (i = 0; i < m; i++)
        link(head2);
    printf("第2个链表当前元素如下\n");
    pin(head2);
    printf("\n");

    printf("有公共节点的链表1如下：\n");
    Ptrstu p2 = head2->node;
    Ptrstu p1 = head1, temp;
    while (p1->node != NULL)
        p1 = p1->node;
    i = 0;
    srand((int)time(NULL));
    n = rand() % 4 + 1;
    while (p2->node != NULL && i < n)
    {
        p2 = p2->node;
        i++;
    }
    p1->node = p2;
    pin(head1);
    printf("\n");
    seek(head1, head2);
    return 0;
}
