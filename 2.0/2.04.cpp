//删除链表中的重复元素
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

int main(int argc, char const *argv[])
{
    int n, i;
    scanf("%d", &n);
    struct node *head, *tail, *p, *q, *t;
    head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    tail = head;

    //向单向链表中插入值
    for (i = 0; i < n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &p->data);
        p->next = NULL;
        tail->next = p;
        tail = p;
    }

    //通过两个指针的遍历来实现删除重复元素。类似于数组里面的双层循环
    p = head->next;
    while (p->next != NULL)
    {
        q = p->next;
        t = p;
        while (q != NULL)
        {
            if (p->data == q->data || p->data == (-1) * (q->data))
            {
                q = q->next;
                t->next = q;
            }
            else
            {
                q = q->next;
                t = t->next;
            }
        }
        if (p->next == NULL)
        {
            break;
        }
        else
        {
            p = p->next;
        }
    }

    p = head->next;
    while (p)
    {
        if (p->next)
        {
            printf("%d ", p->data);
        }
        else
        {
            printf("%d\n", p->data);
        }
        p = p->next;
    }
    return 0;
}
