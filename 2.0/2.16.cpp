// 后缀表达式  （逆波兰表达式， 运算发放在后面）

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef double DateType;

typedef struct RpnNode
{
    DateType data;
    struct RpnNode *next;
} RpnNode, *RpnNodeList;

typedef struct RpnNodeSave
{
    RpnNodeList top;
    int count;
} RpnNodeSave;

// 进站
void Push(RpnNodeSave *L, DateType data)
{
    RpnNode *node, *top;

    top = L->top;

    node = (RpnNode *)malloc(sizeof(RpnNode));
    node->data = data;
    node->next = top;

    L->top = node;
    L->count++;
}

// 出站
void Pop(RpnNodeSave *ptr, DateType *e)
{
    RpnNode *node, *topnext;

    node = ptr->top;
    *e = node->data;
    topnext = node->next;

    free(node);

    ptr->top = topnext;
    ptr->count--;
}

// 打印值
void printStack(RpnNode *L)
{
    while (L->next)
    {
        printf("%f->", L->data);
        L = L->next;
    }

    printf("\n");
}

int main(int argc, char const *argv[])
{
    /* code */
    char data;
    char str[10];
    int i = 0;

    DateType start, end, store, result;

    RpnNode *stractHead;
    stractHead = (RpnNodeList)malloc(sizeof(RpnNode));
    stractHead->next = NULL;

    RpnNodeSave *stractPtr;
    stractPtr = (RpnNodeSave *)malloc(sizeof(RpnNodeSave));
    stractPtr->top = stractHead;
    stractPtr->count = 0;

    printf("请输入一串后缀表达式, 以Enter结束: \n");
    scanf("%c", &data);
    while (data != '\n')
    {

        while (isdigit(data) || '.' == data)
        {
            str[i++] = data;
            str[i] = '\0';
            if (i >= 10)
            {
                printf("输入的单个数据过大\n");
                return -1;
            }

            scanf("%c", &data);
            if (' ' == data)
            {
                store = atof(str);

                Push(stractPtr, store);
                i = 0;
                break;
            }
        }

        switch (data)
        {
        case '+':
            Pop(stractPtr, &end);
            Pop(stractPtr, &start);

            Push(stractPtr, start + end);
            break;
        case '-':
            Pop(stractPtr, &end);
            Pop(stractPtr, &start);

            Push(stractPtr, start - end);
            break;
        case '*':
            Pop(stractPtr, &end);
            Pop(stractPtr, &start);

            Push(stractPtr, start * end);
            break;
        case '/':
            Pop(stractPtr, &end);
            Pop(stractPtr, &start);

            if (end == 0)
            {
                printf("输入错误,除数不能为0\n");
                return -1;
            }
            Push(stractPtr, start / end);
            break;
        }
        scanf("%c", &data);
    }

    Pop(stractPtr, &result);
    printf("result: %f \n", result);

    getchar();
    return 0;
}
