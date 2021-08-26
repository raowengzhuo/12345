//合并有序链表
#include <stdio.h>
#include <stdlib.h>
typedef struct List
{
    int a;
    struct List *next;
} list;
void newList(list *l)
{
    //初始化头节点
    l->next = NULL;
}
void setList(list *l)
{
    //建立链表
    int i = 1;
    int j;
    while (i)
    {
        scanf("%d", &j);
        if (j == -1)
        {
            i = 0;
        }
        else
        {
            list *l1 = (list *)malloc(sizeof(list)); //为新的结点分派内存
            l1->a = j; //储存数据
            /*
            将最后结点的next区域指向新结点
            将新结点的next区域指向设置为空
            */
            l->next = l1;
            l1->next = NULL;
            l = l->next;
        }
    }
}
void printfList(list *l)
{
    printf("该链表内容为：\n");
    while (l->next)
    {
        printf("%d\t", l->next->a);
        l = l->next;
    }
    printf("\n");
}
list *add(list *LA, list *LB)
{
    //记录两个链表的头结点
    list *la = LA;
    list *l = LA;
    list *lb = LB;
    //移动指针
    LA = LA->next;
    LB = LB->next;
    la->next = NULL;
    while (LA != NULL && LB != NULL)
    {
        /*
        将两个结点的数据进行比较，数据较小的结点接在头结点后面，
        */
        if (LA->a < LB->a)
        {
            la->next = LA;
            la = LA;
            LA = LA->next;
        }
        else
        {
            la->next = LB;
            la = LB;
            LB = LB->next;
        }
    }
    //若其中一个链表的结点已经全接在新表中则将另一个链表的剩余结点接在新表的后面
    if (LA)
    {
        la->next = LA;
    }
    if (LB)
    {
        la->next = LB;
    }
    free(lb);
    return l;
}
int main()
{

    //为结点分配内存
    list *LA = (list *)malloc(sizeof(list));
    list *LB = (list *)malloc(sizeof(list));
    //初始化结点
    newList(LA);
    newList(LB);
    //建立链表
    setList(LA);
    setList(LB);
    //输出链表的内容
    printf("LA的数据:\n");
    printfList(LA);
    printf("LB的数据:\n");
    printfList(LB);
    list *LC = add(LA, LB);
    //输出合并后的新表
    printfList(LC);
    system("pause");
    return 0;
}