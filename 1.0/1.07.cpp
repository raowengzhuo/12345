//二维数组的查找
#include <stdio.h>
#define Col 4
int Yang(int arr[][Col], int val)
{
    int i = 0;
    int j = Col - 1;
    int tmp = arr[i][j]; //找到左上角的数
    while (1)
    {
        if (tmp == val)
        {
            return 1;
        }
        else if (tmp < val && j >= 0) //小于要找的数，在下一行寻找
        {
            tmp = arr[++i][j];
        }
        else if (tmp > val && j >= 0) //大于要找的数，从该列向前找
        {
            tmp = arr[i][--j];
        }
        else
            return 0;
    }
}
int main()
{
    int i, j;
    int a;
    int arr[4][Col] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 15, 16, 17, 18, 19};
    printf("数组为：\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
    printf("请输入一个数：");
    scanf("%d", &a);
    if (Yang(arr, a))
    {
        printf("  %d在该矩阵中\n", a);
    }
    else
    {
        printf("  %d不在该矩阵中\n", a);
    }
    return 0;
}