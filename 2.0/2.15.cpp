/*日程管理*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <pthread.h>
#include <time.h>
#include <string.h>

pthread_t ntid;
pthread_t tid;
struct node
{
    char s[200];
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    struct node *next;
};
struct node *head;

struct node *stusort()
{
    struct node *pre, *p, *temp;
    pre = head;
    while (pre->next->next != NULL)
    {
        p = head->next;
        pre = head;
        while (p->next != NULL)
        {
            if (p->year > p->next->year)
            {
                pre->next = p->next;
                temp = p->next->next;
                p->next->next = p;
                p->next = temp;
                p = pre->next;
            }
            else if (p->year == p->next->year)
            {
                if (p->month > p->next->month)
                {
                    pre->next = p->next;
                    temp = p->next->next;
                    p->next->next = p;
                    p->next = temp;
                    p = pre->next;
                }
                else if (p->month == p->next->month)
                {
                    if (p->day > p->next->day)
                    {
                        pre->next = p->next;
                        temp = p->next->next;
                        p->next->next = p;
                        p->next = temp;
                        p = pre->next;
                    }
                    else if (p->day == p->next->day)
                    {
                        if (p->hour > p->next->hour)
                        {
                            pre->next = p->next;
                            temp = p->next->next;
                            p->next->next = p;
                            p->next = temp;
                            p = pre->next;
                        }
                        else if (p->hour == p->next->hour)
                        {
                            if (p->minute > p->next->minute)
                            {
                                pre->next = p->next;
                                temp = p->next->next;
                                p->next->next = p;
                                p->next = temp;
                                p = pre->next;
                            }
                            else if (p->minute == p->next->minute)
                            {
                                if (p->second > p->next->second)
                                {
                                    pre->next = p->next;
                                    temp = p->next->next;
                                    p->next->next = p;
                                    p->next = temp;
                                    p = pre->next;
                                }
                            }
                        }
                    }
                }
            }

            p = p->next;
            pre = pre->next;
        }
    }
    return head;
}
void show()
{
    struct node *tail;
    tail = head->next;
    while (tail)
    {
        printf("%s\n", tail->s);
        tail = tail->next;
    }
}
void *threadone(void *)
{
    struct node *p;
    p = (node *)malloc(sizeof(node));
    Sleep(1000);
    while (1)
    {
        p = head->next;
        while (p)
        {
            time_t t;
            struct tm *lt;
            time(&t);
            lt = localtime(&t);
            if (lt->tm_year + 1900 == p->year && lt->tm_mon + 1 == p->month && lt->tm_mday == p->day && lt->tm_min == p->minute && lt->tm_sec == p->second)
            {
                printf("%s\n", p->s);
                Sleep(1000);
            }
            p = p->next;
        }
    }
    return NULL;
}

void *threadtwo(void *)
{
    printf("程序开始运行\n");
    head->next = NULL;
    while (1)
    {
        printf("请选择一项要执行的功能\n");
        printf("1     插入一个事件安排\n");
        printf("2     对已插入的事件进行排序并输出\n");
        printf("3     按时间删除一个事件并输出剩下的事件\n");
        printf("4     按事件内容删除一个事件并输出剩下的事件\n");
        printf("5     查找一个具体事件并输出其时间\n");
        printf("6     修改一个事件的具体时间并输出\n");
        printf("7     结束程序\n");
        int ch;
        scanf("%d", &ch);
        if (ch == 1)
        {
            struct node *p;
            p = (struct node *)malloc(sizeof(struct node));
            printf("请输入事件的时间和内容，格式如2018 2 2 18 20 15 上课,中间以一个空格隔开\n");
            scanf("%d %d %d %d %d %d %s", &p->year, &p->month, &p->day, &p->hour, &p->minute, &p->second, p->s);
            p->next = head->next;
            head->next = p;
        }
        else if (ch == 2)
        {
            head = stusort();
            struct node *q;
            q = head->next;
            while (q)
            {
                printf("%s\n", q->s);
                q = q->next;
            }
        }
        else if (ch == 3)
        {
            printf("请输入要删除事件的具体时间,年 月 日 时 分 秒，如2018 2 2 18 20 15，中间以一个空格隔开\n");
            int y, m, d, h, minu, sd;
            scanf("%d %d %d %d %d %d", &y, &m, &d, &h, &minu, &sd);
            struct node *p1;
            struct node *p2;
            p1 = head;
            while (p1->next != NULL)
            {
                if (p1->year != y || p1->month != m || p1->day != d || p1->hour != h || p1->minute != minu || p1->second != sd)
                {
                    p2 = p1;
                    p1 = p1->next;
                }
                if (p1->year == y && p1->month == m && p1->day == d && p1->hour == h && p1->minute == minu)
                {
                    p2->next = p1->next;
                    free(p1);
                    if (p2->next)
                    {
                        p1 = p2->next;
                    }
                }
            }
            printf("事件已成功删除，以下为剩下的事件\n");
            show();
        }
        else if (ch == 4)
        {
            printf("请输入要删除事件的具体内容\n");
            char s1[200];
            scanf("%s", s1);
            struct node *p1;
            struct node *p2;
            p1 = head;
            while (p1->next != NULL)
            {
                if (strcmp(p1->s, s1) != 0)
                {
                    p2 = p1;
                    p1 = p1->next;
                }
                if (strcmp(p1->s, s1) == 0)
                {
                    p2->next = p1->next;
                    free(p1);
                    p1 = p2->next;
                }
            }
            printf("事件已成功删除，以下为剩下的事件\n");
            show();
        }
        else if (ch == 5)
        {
            printf("请输入要查找的具体事件\n");
            char s2[100];
            scanf("%s", s2);
            struct node *p1;
            p1 = head->next;
            while (p1)
            {
                if (strcmp(p1->s, s2) != 0)
                {
                    p1 = p1->next;
                }
                else
                {
                    printf("该事件的时间为%d年%d月%d日%d时%d分%d秒\n", p1->year, p1->month, p1->day, p1->hour, p1->minute, p1->second);
                    break;
                }
            }
        }
        else if (ch == 6)
        {
            printf("请输入要修改的事件，并输入修改之后的时间，时间格式按年 月 日 时 分 秒输入\n");
            char s_after[200];
            int y_a, mon_a, day_a, hour_a, minute_a, sec_a;
            scanf("%s %d %d %d %d %d %d", s_after, &y_a, &mon_a, &day_a, &hour_a, &minute_a, &sec_a);
            struct node *p5;
            p5 = head->next;
            while (p5)
            {
                if (strcmp(p5->s, s_after) != 0)
                {
                    p5 = p5->next;
                }
                else
                {
                    p5->year = y_a;
                    p5->month = mon_a;
                    p5->day = day_a;
                    p5->hour = hour_a;
                    p5->minute = minute_a;
                    p5->second = sec_a;
                    printf("事件时间修改成功，改为%d年%d月%d日%d时%d分%d秒\n", y_a, mon_a, day_a, hour_a, minute_a, sec_a);
                    break;
                }
            }
        }
        else if (ch == 7)
        {
            struct node *q, *r;
            q = head;
            r = q;
            while (q)
            {
                r = q->next;
                free(q);
                q = r;
            }
            exit(0);
        }
    }
    return NULL;
}
int main()
{
    head = (struct node *)malloc(sizeof(struct node));
    pthread_create(&ntid, NULL, threadtwo, NULL);
    pthread_create(&tid, NULL, threadone, NULL);
    Sleep(1000000000);
}