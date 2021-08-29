//双向链表的快速排序
#include <stdio.h>
#include <stdlib.h>
typedef struct _Box //结构体
{
    struct _Box *prev;
    int num;
    struct _Box *next;
} Box;
Box *Box_Creathead() //创建一个头节点
{
    Box *p = (Box *)malloc(sizeof(Box));
    p->prev = NULL;
    p->next = NULL;
    return p;
}
void Box_Add(Box *box_head) //头插法创建双向链表
{
    int num;
    while (scanf("%d", &num) == 1)
    {
        Box *p = (Box *)malloc(sizeof(Box));
        p->num = num;
        p->next = box_head->next;
        p->prev = box_head;
        if (box_head->next)
        {
            box_head->next->prev = p;
        }
        box_head->next = p;
    }
}
void Box_Qsort(Box *low, Box *high) //快排核心内容
{
    Box *i = low;
    Box *j = high;
    Box *key = (Box *)malloc(sizeof(Box)); //保存节点数据
    if (low == NULL)
    {
        return;
    }
    key->num = low->num;
    if (low == high || low->prev == high)
    {
        return;
    }
    while (low != high && low->prev != high)
    {
        for (; low != high && low->prev != high && key->num <= high->num; high = high->prev)
            ;
        if (key->num > high->num)
        {
            low->num = high->num;
        }
        for (; low != high && low->prev != high && key->num >= low->num; low = low->next)
            ;
        if (key->num < low->num)
        {
            high->num = low->num;
        }
    }
    low->num = key->num;
    Box_Qsort(i, low->prev); //这里因为有了头节点所以不用考虑
    Box_Qsort(low->next, j); //如果不给最后一个有值的节点接一个节点,就会访问到不确定的内存
}
void Box_Print(Box *box_head) //显示双向链表内容
{
    Box *p = box_head->next;
    while (p->next)
    {
        printf("%d ", p->num);
        p = p->next;
    }
    printf("\n");
}
Box *Box_FindBase(Box *box_head) //找到链表最后一个节点
{
    Box *p = box_head->next;
    if (!p)
    {
        return box_head;
    }
    while (p->next)
    {
        p = p->next;
    }
    return p;
}
//没用..
void Box_CreatBase(Box *high) //为最后一个节点接一个空的节点
{
    Box *p = (Box *)malloc(sizeof(Box));
    p->next = NULL;
    p->prev = high;
    high->next = p;
}
int main()
{
    Box *box_head = Box_Creathead();    //头节点
    Box_Add(box_head);                  //添加数据
    Box *low = box_head->next;          //第一个有数据的节点
    Box *high = Box_FindBase(box_head); //最后一个有数据的点
    //Box_CreatBase(high);//为最后一个有数据的节点接一个节点
    Box_Print(box_head);  //展示没有排序前的链表(因为是头插法,所以是反着输出的)
    Box_Qsort(low, high); //排序
    Box_Print(box_head);  //展示经过排序后的内容
    return 0;
}
