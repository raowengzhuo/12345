//循环链表-操作集
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;

typedef struct Node *LinkList;

LinkList Creat_list()
{
    int len;
    printf("Please enter the length of the single circular linked list: ");
    scanf("%d", &len);
    LinkList pHead = (LinkList)malloc(sizeof(Node));
    if (pHead == NULL)
    {
        printf("Insufficient memory space!!");
        exit(0);
    }
    pHead->data = 0;
    pHead->next = pHead;
    LinkList pTail = pHead;
    int num;
    for (int i = 0; i < len; i++)
    {
        printf("Please enter the element of the node: ");
        scanf("%d", &num);
        LinkList pNew = (LinkList)malloc(sizeof(Node));
        if (pNew == NULL)
        {
            printf("Insufficient memory space!!");
            exit(0);
        }
        pNew->data = num;
        pNew->next = pHead;
        pTail->next = pNew;
        pTail = pNew;
    }

    return pTail;
}

void traverse(LinkList rear)
{
    LinkList pHead = rear->next;
    LinkList p = rear->next->next;

    while (p != pHead)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int GetLengthLink(LinkList rear)
{
    int length = 0;
    LinkList pHead = rear->next;
    LinkList p = rear->next->next;

    while (p != pHead)
    {
        length++;
        p = p->next;
    }
    return length;
}

void insert_list(LinkList &rear)
{
    LinkList pHead = rear->next;
    int index, num;
    printf("Please enter the location to insert: ");
    scanf("%d", &index);

    if (index > 0 && index < GetLengthLink(rear) + 1)
    {
        printf("Please enter the value to insert: ");
        scanf("%d", &num);
        LinkList pNew = (LinkList)malloc(sizeof(Node));
        if (pNew == NULL)
        {
            printf("Insufficient memory space!!");
            exit(0);
        }
        while (1)
        {
            index--;
            if (0 == index)
                break;
            pHead = pHead->next;
        }
        pNew->data = num;
        pNew->next = pHead->next;
        pHead->next = pNew;
    }
    else
    {
        printf("The enter location is illegal!!\n");
    }
}

void Del_List(LinkList &rear, ElemType &e)
{
    LinkList pHead = rear->next;
    LinkList temp;
    int pos;
    printf("Please enter the node` location to delete: ");
    scanf("%d", &pos);
    if (pos > 0 && pos < GetLengthLink(rear) + 1)
    {
        while (1)
        {
            pos--;
            if (0 == pos)
            {
                break;
            }
            pHead = pHead->next;
        }
        temp = pHead->next->next;
        e = pHead->next->data;
        free(pHead->next);
        pHead->next = temp;
    }
    else
    {
        printf("The enter location is illegal!!\n");
    }
}

bool Free_List(LinkList &rear)
{
    // LinkList pHead = rear->next;
    LinkList p = NULL;

    while (rear != NULL)
    {
        if (rear == rear->next)
        {
            free(rear);
            rear = NULL;
        }
        else
        {
            p = rear->next->next;
            free(rear->next);
            rear->next = p;
        }
    }
    return true;
}

void Merge_List(LinkList rear, LinkList &rear2)
{
    LinkList p;
    LinkList temp_Rear = rear;
    p = temp_Rear->next;
    temp_Rear->next = rear2->next->next;
    LinkList q = rear2->next;
    rear2->next = p;
    free(q);
}

int main()
{

    LinkList rear = Creat_list(); //Create a single circular linked list

    traverse(rear);

    insert_list(rear); //Insert  element in the single circular linked list

    traverse(rear);

    ElemType e;
    Del_List(rear, e); //Delete a node of the single circular linked list
    printf("The value of the deleted node : %d\n", e);
    traverse(rear);

    printf("Creat the second single circular linked list:\n");
    LinkList rear2 = Creat_list();

    traverse(rear2);

    Merge_List(rear, rear2); //Merge two single circular linked list

    traverse(rear2);

    if (Free_List(rear2))
        printf("Clear the list is ok!!");

    return 0;
}
