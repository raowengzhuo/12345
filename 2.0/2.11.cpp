//链式表操作集
#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode
{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find(List L, ElementType X);
List Insert(List L, ElementType X, Position P);
List Delete(List L, Position P);

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if (L == ERROR)
            printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &X);
        P = Find(L, X);
        if (P == ERROR)
            printf("Finding Error: %d is not in.\n", X);
        else
        {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if (L == ERROR)
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if (L == ERROR)
        printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if (tmp != ERROR)
        printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if (tmp != ERROR)
        printf("Wrong Answer\n");
    for (P = L; P; P = P->Next)
        printf("%d ", P->Data);
    return 0;
}
/* 你的代码将被嵌在这里 */
/* 你的代码将被嵌在这里 */
Position Find(List L, ElementType X)
{
    List p = L;
    while (p != NULL)
    { //不能用!p,后面的也是,大坑
        if (p->Data == X)
            return p;
        p = p->Next;
    }
    return ERROR;
}

List Insert(List L, ElementType X, Position P)
{
    List p = L;

    if (P == L)
    { //表头插入,下面的循环是判断p->Next空不空,所以要考虑表头
        List s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = P;
        return s;
    }

    while (p != NULL)
    {
        if (p->Next == P)
        {
            List n = (List)malloc(sizeof(struct LNode));
            n->Data = X;
            n->Next = P;
            p->Next = n;
            return L;
        }
        p = p->Next;
    }
    printf("Wrong Position for Insertion\n");
    return ERROR;
}

List Delete(List L, Position P)
{
    List p = L, t;
    if (P == L)
    { //删除表头
        p = p->Next;
        free(L);
        return p;
    }

    while (p != NULL)
    {
        if (p->Next == P)
        {
            t = p->Next->Next;
            p->Next = t;
            free(P);
            return L;
        }
        p = p->Next;
    }
    printf("Wrong Position for Deletion\n");
    return ERROR;
}
