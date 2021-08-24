//重建二叉树
#include <stdio.h>
#include <stdlib.h>

/*二叉树结构体*/
typedef struct Tree
{
    int data;
    struct Tree *leftTree;
    struct Tree *rightTree;
} Tree;
/*序列结构体*/
typedef struct List
{
    int data[10];
    int size;
} List;
/*
返回值：重建的二叉树的根节点
参数：前序序列结构体
     中序序列结构体
*/
Tree *rebuildTree(List *preList, List *midList)
{
    /*判断*/
    if (midList->size == 0)
        return NULL;
    /*创建根节点*/
    Tree *root = NULL;
    // BiTree root = NULL;
    if (preList->size != 0)
    {
        /*跟节点初始化*/
        // root = (Tree *)malloc(sizeof(Tree));
        root = (Tree *)malloc(sizeof(Tree));
        /*前序序列的第一个元素是 新的 二叉树的跟节点*/
        root->data = preList->data[0];
    }

    int i = 0, j = 0;
    int father = 0; /*根节点在中序序列的位置  用于 左子树集合 和 右子树集合 的确定*/
    for (i = 0; i < midList->size; i++)
    {
        if (midList->data[i] == preList->data[0])
        {
            father = i;
            break;
        }
    }

    /*分别定义存放 前序序列 和 中序序列 的 左子树集合 和 右子树集合 的 结构体变量*/
    List pre_left, pre_right, mid_left, mid_right;
    /*初始化*/
    pre_left.size = pre_right.size = mid_left.size = mid_right.size = 0;

    /*根据变量i(根节点在中序节点的位置)，给前序节点和中序交接点的 左子树集合 赋值*/
    for (i = 0; i < father; i++)
    {
        /*preList[0]为根节点，所以加一*/
        pre_left.data[i] = preList->data[i + 1];
        pre_left.size++;
        mid_left.data[i] = midList->data[i];
        mid_left.size++;
    }

    /*给前序节点和中序交接点的 右子树集合 赋值*/
    for (i = father + 1, j = 0; i < midList->size; i++, j++)
    {
        pre_right.data[j] = preList->data[i];
        pre_right.size++;
        mid_right.data[j] = midList->data[i];
        mid_right.size++;
    }

    /*递归调用将左子树看成完整的一棵树找出根结点作为主根结点的左子树*/
    /*注意是  root->leftTree =  */
    root->leftTree = rebuildTree(&pre_left, &mid_left);
    /*递归调用将右子树看成完整的一棵树找出根结点作为主根结点的右子树*/
    /*注意是 root->rightTree */
    root->rightTree = rebuildTree(&pre_right, &mid_right);
    return root;
}
/*先序递归遍历*/
void pre_travel(Tree *tree)
{
    if (tree) /*如果节点不为空，就进入*/
    {
        printf("%d   ", tree->data);
        pre_travel(tree->leftTree);
        pre_travel(tree->rightTree);
    }
}
/*中序遍历*/
void mid_travel(Tree *tree)
{
    if (tree)
    {
        mid_travel(tree->leftTree);
        printf("%d   ", tree->data);
        mid_travel(tree->rightTree);
    }
}

int main(void)
{
    Tree *tree;
    List preList;
    List midList;
    preList.size = 0;
    midList.size = 0;
    int i = 0, num = 0;

    printf("请输入共有多少个结点：\n");
    scanf("%d", &num);
    printf("请输入先序序列：\n");
    /*创建前序序列*/
    for (i = 0; i < num; i++)
    {
        scanf("%d", &preList.data[i]);
        preList.size++;
    }
    /*创建中序序列*/
    printf("请输入中序序列：\n");
    for (i = 0; i < num; i++)
    {
        scanf(" %d", &midList.data[i]);
        midList.size++;
    }

    /*调用重建二叉树函数*/
    tree = rebuildTree(&preList, &midList);

    /*前序遍历*/
    pre_travel(tree);

    /*中序遍历*/
    mid_travel(tree);
    return 0;
}
