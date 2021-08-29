//链表快排
#include <stdio.h>
#include <malloc.h>
#define LEN sizeof(struct Student)
struct Student //结构体声明
{
    long num;
    int score;
    struct Student *next;
};
int n;

struct Student *creat() //创建单向链表
{
    struct Student *head = NULL, *p_before, *p_later;
    p_before = p_later = (struct Student *)malloc(LEN);
    scanf("%ld%d", &p_before->num, &p_before->score);
    while (p_before->num != 0)
    {
        n++;
        if (n == 1)
            head = p_before;
        else
            p_later->next = p_before;
        p_later = p_before;
        p_before = (struct Student *)malloc(LEN);
        scanf("%ld%d", &p_before->num, &p_before->score);
    }
    p_later->next = NULL;
    free(p_before);
    return head;
}
//快排   
struct Student *Link_Quick_Sort(struct Student **head, struct Student **end)                 
{                                                                                            
    struct Student *big_head = NULL, *big_end = NULL, *small_head = NULL, *small_end = NULL; 
    struct Student *big_tail = NULL, *small_tail = NULL;                                     
    int key = (*head)->score;                                                                
    struct Student *traversal = (*head)->next;                                               
    (*head)->next = NULL;
    struct Student *p = NULL;
    while (traversal != NULL)
    {
        if (traversal->score > key)
        {
            if (big_head == NULL)
            {
                big_head = traversal;
                big_tail = traversal;
            }
            else
            {
                big_tail->next = traversal;
                big_tail = traversal;
            }
            traversal = traversal->next;
            big_tail->next = NULL;
        }
        else
        {
            if (small_head == NULL)
            {
                small_head = traversal;
                small_tail = traversal;
            }
            else
            {
                small_tail->next = traversal;
                small_tail = traversal;
            }
            traversal = traversal->next;
            small_tail->next = NULL;
        }
    }
    big_end = big_tail;
    small_end = small_tail;
    if (big_head != NULL && big_head->next != NULL)
    {
        Link_Quick_Sort(&big_head, &big_end);
    }
    if (small_head != NULL && small_head->next != NULL)
    {
        Link_Quick_Sort(&small_head, &small_end);
    }
    if (big_end != NULL && small_head != NULL)
    {
        big_end->next = (*head);
        (*head)->next = small_head;
        (*head) = big_head;
        if (end == NULL)
        {
            end = &p;
        }
        (*end) = small_end;
    }
    else if (big_end != NULL)
    {
        big_end->next = (*head);
        if (end == NULL)
        {
            end = &p;
        }
        (*end) = (*head);
        (*head) = big_head;
    }
    else if (small_head != NULL)
    {
        (*head)->next = small_head;
        if (end == NULL)
        {
            end = &p;
        }
        (*end) = small_end;
    }
    return (*head);
}

int main() //用main函数来测试
{
    printf("请依次输入学生的学和姓名\n");
    printf("学号和姓名间以空格隔开\n");
    printf("输入0 0结束\n");
    struct Student *pt, *p;
    struct Student *creat();
    pt = creat();
    int i;
    for (p = pt, i = 1; i <= n; i++, p = p->next)
        printf("num=%ld score=%d\n", p->num, p->score);
    printf("排序后：\n");
    p = Link_Quick_Sort(&pt, NULL);       
    for (i = 1; i <= n; i++, p = p->next) 
        printf("第%d名： num=%ld score=%d\n", i, p->num, p->score);
}