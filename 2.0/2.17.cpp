//链表求和
#include <stdio.h>
#include <stdlib.h>
struct PolyNode;
typedef struct PolyNode *PtrNode;
typedef PtrNode polynomial;
struct PolyNode
{
    int nCoef;
    int nExpon;
    PtrNode Next;
};
/*some function are also given*/
polynomial MakeEmpty(polynomial p);
void InsertNode(int Coef, int expon, polynomial poly);
void PrintPoly(polynomial p);
void readPoly(polynomial poly);
void InsertNode(int Coef, int expon, polynomial poly)
{
    PtrNode p = poly->Next;
    PtrNode pPre = poly;
    while (p)
    {
        if (p->nExpon == expon)
        {
            p->nCoef += Coef;
            break;
        }
        else if (p->nExpon > expon)
        {
            p = p->Next;
            pPre = pPre->Next;
        }
        else
        {
            PtrNode temp;
            temp = (PtrNode)malloc(sizeof(struct PolyNode));
            temp->nCoef = Coef;
            temp->nExpon = expon;
            pPre->Next = temp;
            temp->Next = p;
            break;
        }
    }
    if (p == NULL)
    {
        PtrNode temp;
        temp = (PtrNode)malloc(sizeof(struct PolyNode));
        temp->nCoef = Coef;
        temp->nExpon = expon;
        pPre->Next = temp;
        temp->Next = NULL;
    }
}
polynomial MakeEmpty(polynomial p)
{
    p = (polynomial)malloc(sizeof(struct PolyNode));
    if (p == NULL)
        printf("Out of memory!");
    p->Next = NULL;
    return p;
}
void PrintPoly(polynomial p) //多项式链表打印函数
{
    while (p->Next)
    {
        printf("%d", p->Next->nCoef);
        if (p->Next->nExpon != 0)
        {
            printf("x^%d", p->Next->nExpon);
        }
        p = p->Next;
        if (p->Next != NULL)
        {
            if (p->Next->nCoef > 0)
            {
                printf("+");
            }
        }
    }
    printf("\n");
}
void readPoly(polynomial poly)
{
    printf("Reading poly:\n");
    int n, coef, expon;
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &coef);
        scanf("%d", &expon);
        InsertNode(coef, expon, poly);
    }
}
void Attach(int c, int e, PtrNode p) //在p后面添加节点
{
    polynomial temp = (polynomial)malloc(sizeof(struct PolyNode));
    temp->nCoef = c;
    temp->nExpon = e;
    temp->Next = NULL;
    p->Next = temp;
    p = temp;
}
polynomial initPoly(polynomial p1, polynomial p2) //用p1第一项乘以p2初始化结果多项式
{
    polynomial p, t, rear;
    p = (polynomial)malloc(sizeof(struct PolyNode));
    p->Next = NULL;
    t = (polynomial)malloc(sizeof(struct PolyNode));
    t = p2;
    rear = p;
    while (t)
    {
        Attach((p1->nCoef) * (t->nCoef), p1->nExpon + t->nExpon, rear);
        t = t->Next;
    }
    return p; //此时返回的多项式含头结点
}
polynomial product(polynomial p1, polynomial p2)
{
    polynomial p3 = initPoly(p1, p2); //新多项式
    polynomial t1, t2, rear, temp;
    int c, e;
    t1 = p1->Next;
    while (t1)
    {
        rear = p3;
        t2 = p2;
        while (t2)
        {
            c = (t1->nCoef) * (t2->nCoef);
            e = (t1->nExpon) + (t2->nExpon);
            while ((rear->Next) && (rear->Next->nExpon > e)) //移动rear，找到插入的位置
            {
                rear = rear->Next;
            }
            if ((rear->Next) && (rear->Next->nExpon == e)) //合并同类项
            {
                if (rear->Next->nCoef + c)
                {
                    rear->Next->nCoef += c;
                }
                else //同类项系数为0，删去该节点
                {
                    temp = rear->Next;
                    rear->Next = temp->Next;
                    free(temp);
                }
            }
            else //不能合并同类项部分即插入节点
            {
                temp = (polynomial)malloc(sizeof(struct PolyNode));
                temp->nCoef = c;
                temp->nExpon = e;
                temp->Next = rear->Next;
                rear->Next = temp;
            }
            t2 = t2->Next;
        }
        t1 = t1->Next;
    }
    temp = p3;
    p3 = p3->Next;
    free(temp);
    return p3;
}
int main()
{
    polynomial p1, p2, result;
    p1 = MakeEmpty(NULL);
    p2 = MakeEmpty(NULL);
    readPoly(p1);
    readPoly(p2);
    result = product(p1, p2);
    PrintPoly(p1);
    PrintPoly(p2);
    PrintPoly(result);
    return 0;
}