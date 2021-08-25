//合并两个有序数组
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10010
#define ElemType int
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} SeqList;
void InitList(SeqList &l)
{
    l.length = 0;
}
void CreateList(SeqList &l, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("输入元素：");
        int elem;
        scanf("%d", &elem);
        l.data[i] = elem;
        l.length++;
    }
}
void Combination(SeqList &l1, SeqList &l2, SeqList &l3)
{
    int i = 0, j = 0, k = 0;
    while ((i != l1.length) && (j != l2.length))
    {
        if (l1.data[i] > l2.data[j])
        {
            l3.data[k++] = l2.data[j++];
        }
        else
        {
            l3.data[k++] = l1.data[i++];
        }
        l3.length++;
    } 
    while (i < l1.length)
    {
        l3.data[k++] = l1.data[i++];
        l3.length++;
    }
    while (j < l2.length)
    {
        l3.data[k++] = l2.data[j++];
        l3.length++;
    }
}
void display(SeqList &l)
{
    for (int i = 0; i < l.length; i++)
    {
        printf("%d ", l.data[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("输入顺序表元素个数：");
    scanf("%d", &n);
    SeqList l1, l2, l3;
    //顺序表初始化
    InitList(l1);
    InitList(l2);
    InitList(l3);
    //顺序表创建
    printf("创建顺序表1\n");
    CreateList(l1, n);
    printf("创建顺序表2\n");
    CreateList(l2, n);
    printf("顺序表1与2合并\n");
    Combination(l1, l2, l3);
    //顺序表打印
    printf("顺序表合并结果打印\n");
    display(l3);
    return 0;
}
