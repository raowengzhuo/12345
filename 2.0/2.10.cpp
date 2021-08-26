//创建十字链表
#include <stdio.h>
#include <stdlib.h>

#define ERROR 0

typedef struct Bow
{
    char head, tail;

    struct Bow *hlink, *tlink;
} Bow;

typedef struct FirstNode
{
    char data;

    Bow *firIn;
    Bow *firOut;
} FirstNode;

typedef struct
{
    FirstNode list[100];

    int peak, edge;
} total;

int LocalBow(char data, total *G) //查询顶点的位置
{
    int i;
    for (i = 0; i < G->peak; i++)
    {
        if (G->list[i].data == data)
        {
            return i;
        }
    }
    return ERROR;
}

void create(total *G) //创建十字链表
{
    char x, y;
    int k, j, i;
    printf("请输入图的顶点和弧的数量：");
    scanf("%d %d", &G->peak, &G->edge);
    for (i = 0; i < G->peak; i++)
    {
        fflush(stdin);
        printf("请输入第%d个顶点的值:", i + 1);
        scanf("%c", &G->list[i].data);
        G->list[i].firIn = G->list[i].firOut = NULL;
    }
    for (i = 0; i < G->edge; i++)
    {
        fflush(stdin);
        printf("请输入<vi,vj>，中间用英文逗号隔开：");
        scanf("%c,%c", &x, &y);

        Bow *R = (Bow *)malloc(sizeof(Bow));
        k = LocalBow(x, G);
        j = LocalBow(y, G);
        R->head = x;
        R->tail = y;
        R->hlink = G->list[j].firIn;
        R->tlink = G->list[k].firOut;
        G->list[j].firIn = R;
        G->list[k].firOut = R;
    }
}
int main()
{
    total G;
    Bow *t;
    create(&G);
    int i;
    for (i = 0; i < G.peak; i++)
    {
        printf("%c顶点出度情况为：\n", G.list[i].data);
        t = G.list[i].firOut;
        if (!t)
            printf("无");
        while (t)
        {
            printf("%c->%c ", t->head, t->tail);
            t = t->tlink;
        }
        printf("\n");
        t = G.list[i].firIn;
        printf("%c顶点入度情况为：\n", G.list[i].data);
        if (!t)
            printf("无");
        while (t)
        {
            printf("%c->%c ", t->head, t->tail);
            t = t->hlink;
        }
        printf("\n");
    }
    return 0;
}
