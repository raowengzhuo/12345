//数组中未出现的最小正整数
#include <stdio.h>
#include <stdlib.h>
int GetMissMin(int n, int *arr, int length) //获取未出现的最小正整数
{
    int i;
    for (i = 0; i < length; i++)
    {
        if (arr[i] == n)
        {
            n++;
            return GetMissMin(n, arr, length);
        }
    }
    return n;
}

int main()
{
    printf("请输入数组的长度:\n");
    int length;
    scanf("%d", &length);
    int arr[length];

    printf("请输入数组元素:\n");
    int i;
    for (i = 0; i < length; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("未出现的最小正整数为:\n");
    int min = GetMissMin(1, arr, length);
    printf("%d\n", min);

    system("pause");
    return 0;
}
