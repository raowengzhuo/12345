//二叉排序树
#include <stdio.h>
#include <stdlib.h>
#define N 10
typedef struct tree
{
    int data;
    struct tree *lchild;
    struct tree *rchild;
} BitTree;

void Sort_Tree(BitTree *bt, int key) //在二叉排序树中插入查找关键字key；
{
    BitTree *parent;
    BitTree *p = (BitTree *)malloc(sizeof(BitTree));
    p->data = key;                //保存结点数据；
    p->lchild = p->rchild = NULL; //左右子树置空；
    BitTree *head = bt;
    while (head) //查找关键字所在的位置；
    {
        parent = head;
        if (key < head->data)    //如果关键字小于结点的数据；
            head = head->lchild; //在左子树上查找；
        else                     //若关键字大于结点的数据
            head = head->rchild; //再右子树上查找；
    }
    //判断添加到左子树还是右子树；
    if (key < parent->data) //小于父结点；
        parent->lchild = p; //添加到左子树；
    else                    //大于父结点；
        parent->rchild = p; //添加到右子树；
}

//中序遍历输出二叉排序树；
void InOrder(BitTree *bt)
{
    if (bt) //树不为空，则执行如下操作；
    {
        InOrder(bt->lchild);     //中序遍历左子树；
        printf("%d ", bt->data); //输出结点数据；
        InOrder(bt->rchild);     //中序遍历右子树；
    }
}

int main(void)
{
    int i,n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    BitTree *bt; //保存二叉排序树根结点；
    printf("原数据:\n");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n\n");

    //初始化根结点；
    bt = (BitTree *)malloc(sizeof(BitTree));
    bt->data = a[0];
    bt->lchild = bt->rchild = NULL;
    //将其他数组数据进行排序；
    for (i = 1; i < N; i++)
        Sort_Tree(bt, a[i]);

    printf("遍历二叉排序树:\n");
    InOrder(bt);
    printf("\n");
    return 0;
}