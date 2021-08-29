#include <stdio.h>
#include <malloc.h>
#define LEN sizeof(struct student)

struct student
{
    long num;
    int score;
    struct student *next;
};

int main()
{
    struct student *create();
    void print(struct student * head);
    void SelectedSort(struct student * head);
    struct student *head;
    head = create();
    print(head);
    SelectedSort(head);
    print(head);
}
int n;
struct student *create()
{
    n = 0;
    struct student *head, *p1, *p2;
    p1 = p2 = (struct student *)malloc(LEN);
    scanf("%ld,%d", &p1->num, &p1->score);
    head = NULL;
    while (p1->num != 0)
    {
        n = n + 1;
        if (n == 1)
        {
            head = p1;
        }
        else
        {
            p2->next = p1;
        }
        p2 = p1;
        p1 = (struct student *)malloc(LEN);
        scanf("%ld,%d", &p1->num, &p1->score);
    }
    p2->next = NULL;
    return (head);
}
void print(struct student *head)
{
    struct student *p;
    p = head;
    printf("%d名学生的成绩分别是：\n", n);
    if (head != NULL)
    {
        do
        {
            printf("%ld,%d\n", p->num, p->score);
            p = p->next;
        } while (p != NULL);
    }
    else
    {
        printf("链表为空");
    }
}
//选择排序
void SelectedSort(struct student *head)
{
    struct student *cur, *p = NULL, *q = NULL;
    cur = head;
    int score = 0, cscore = 0;
    if (cur == NULL || cur->next == NULL)
    {
        return;
    }
    while (cur != NULL)
    {
        p = cur->next;
        q = cur->next;
        score = cur->score;
        cscore = score;
        while (p != NULL)
        {
            if (cscore > p->score)
            {
                cscore = p->score;
                q = p;
            }
            p = p->next;
        }
        if (score != cscore)
        {
            q->score = score;
            cur->score = cscore;
            long temp = cur->num;
            cur->num = q->num;
            q->num = temp;
        }
        cur = cur->next;
    }
}