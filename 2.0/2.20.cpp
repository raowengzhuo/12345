//约瑟夫环
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node, *LinkList; //循环单链表
Node *IntCLinkList()
{
    int n, i;
    LinkList head, tail, temp;
    printf("输入n:");
    scanf("%d", &n);
    tail = head = NULL;
    for (i = 1; i <= n; i++)
    {
        temp = (Node *)malloc(sizeof(Node)); //开辟新节点
        temp->data = i;                      //给节点的值域赋值成i的值
        if (head == NULL)                    //空链表
        {
            head = temp;
        }
        else
        {
            tail->next = temp;
        }
        tail = temp; //尾指针指向新的节点；
    }
    tail->next = head; //指向头，形成环
    return head;
}
int main()
{
    LinkList q = NULL;

    LinkList p = IntCLinkList();
    int m;     //循环变量
    int i = 1; //起始位置
    int j = 3; //开始遍历的位置

    printf("请输入开始循环的m值为:");
    scanf("%d", &m);
    printf("出队列的位置为: ");
    while (p->next != p)
    {
        while (j > 1) //指针走到开始遍历位置
        {
            q = p;
            p = p->next;
            --j;
        }
        q = p;
        p = p->next;
        i++;
        if (i == m)
        {
            printf("  %d ", p->data);
            q->next = p->next;
            free(p);
            p = q->next;
            i = 1; //重新计数
        }
    }
    printf("\n");
    printf("最后一个位置为:%d", p->data);
    free(p);
    return 0;
}