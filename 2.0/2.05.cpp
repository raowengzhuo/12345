//链表排序，链表反转

#include <stdio.h>
#include <stdlib.h>

#define PR printf

typedef struct node
{
    long data;
    struct node *next;
} NODE, *LIST;

NODE *insert_data(NODE *head)
{
    PR("please input the integer datas and end with q:\n");

    while (1)
    {
        char ch[10];
        scanf("%s", ch);

        if (ch[0] == 'q' || ch[0] == 'Q')
        {
            break;
        }
        else
        {
            long indata = strtol(ch, 0, 10);
            NODE *temp = NULL;

            temp = (NODE *)malloc(sizeof(struct node));
            temp->data = indata;
            temp->next = NULL;

            temp->next = head->next;
            head->next = temp;
            head->data++;
        }
    }
    return head;
}

void show_link_list(NODE *head)
{
    NODE *p = NULL;
    if (NULL == head || NULL == head->next) //........, ...;
    {
        return;
    }
    printf("the count of data in link = %d, they are :\n", head->data);
    p = head->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void clear_link_list(NODE *head)
{
    if (NULL == head || NULL == head->next)
    {
        return;
    }
    NODE *pd = head->next;
    for (pd = head->next; pd != NULL; pd = head->next)
    {
        head->next = pd->next;
        free(pd);
    }
}
NODE *FUNC_invert_link_list(NODE *head)
{
    if (head == 0 || head->next == 0)
    {
        return 0;
    }
    NODE *h = head->next;

    NODE *xpre = h;
    NODE *x = h->next;

    for (; xpre->next != 0; x = xpre->next)
    {
        xpre->next = x->next;
        x->next = h;
        h = x;
    }

    head->next = h;
    printf("FUNC_invert_link_list completed!\n");
    return head;
}
void FUNC_sort_list(NODE *head)
{
    if (NULL == head || NULL == head->next || head->next->next == NULL)
    {
        return;
    }
    NODE *h = head;
    NODE *p = h->next;
    NODE *pren = h->next;
    NODE *pn = pren->next;

    while (p->next != NULL)
    {
        while (pn != NULL)
        {
            if (p->data < pn->data)
            {
                pren->next = pn->next;
                pn->next = h->next;
                h->next = pn;
                //printf("    swapped!\n");
            }
            else
            {
                pren = pren->next;
            }
            pn = pren->next;
            p = h->next;
        }

        h = h->next;
        p = h->next;
        pren = h->next;
        pn = pren->next;
    }
    printf("FUNC_sort_list completed!\n");
}

void FUNC_bub_sort_list(NODE *head)
{
    if (NULL == head || NULL == head->next || head->next->next == NULL)
    {
        return;
    }

    NODE *tail = NULL;
    NODE *pre = head;
    NODE *p = pre->next;
#define TRUE 1
#define FALSE 0
    int is_sorted = FALSE; //未排好

    while (pre->next != tail && !is_sorted)
    {
        while (p->next != tail)
        {
            is_sorted = TRUE;
            if (p->next->data > p->data) //如果发生数据交换,说明没有排好
            {
                NODE *pn = p->next;
                p->next = pn->next;
                pn->next = p;
                pre->next = pn;
                is_sorted = FALSE;
            }
            pre = pre->next;
            p = pre->next;
        }

        tail = p;
        pre = head;
        p = pre->next;
    }
    printf("FUNC_bub_sort_list completed!\n");
}

int main()
{
    NODE *head = (NODE *)malloc(sizeof(NODE));
    head->next = NULL;
    head->data = 0;

    insert_data(head);
    show_link_list(head);

    FUNC_sort_list(head);
    show_link_list(head);

    FUNC_invert_link_list(head);
    show_link_list(head);

    FUNC_bub_sort_list(head);
    show_link_list(head);

    clear_link_list(head);
    free(head);
}
/*
please input the integer datas and end with q:
12 21 13 133 14 41 15 51 q
the count of data in link = 8, they are :
51 15 41 14 133 13 21 12

FUNC_sort_list completed!
the count of data in link = 8, they are :
133 51 41 21 15 14 13 12

FUNC_invert_link_list completed!
the count of data in link = 8, they are :
12 13 14 15 21 41 51 133

FUNC_bub_sort_list completed!
the count of data in link = 8, they are :
133 51 41 21 15 14 13 12
Press any key to continue . . .
*/