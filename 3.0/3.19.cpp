//冒泡排序
#include <stdio.h>
#include <stdlib.h>

/**
函数：bubble_order()
功能：使用指针实现冒泡排序
**/

void bubble_order(int *a, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - 1 - i; ++j)
        {
            if (*(a + j) > *(a + j + 1))
            {
                *(a + j) = *(a + j) ^ *(a + j + 1);
                *(a + j + 1) = *(a + j) ^ *(a + j + 1);
                *(a + j) = *(a + j) ^ *(a + j + 1);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int a[20], n;
    printf("请输入要排序元素的个数：\n");
    scanf("%d", &n);
    printf("请输入各个元素\n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", a + i);
    }
    printf("排序前元素的内容为：\n");
    for (int j = 0; j < n; ++j)
    {
        printf("%d ", *(a + j));
    }
    bubble_order(a, n);
    printf("\n排序后元素的内容为：\n");
    for (int j = 0; j < n; ++j)
    {
        printf("%d ", *(a + j));
    }
    printf("\n");
    getchar();
}