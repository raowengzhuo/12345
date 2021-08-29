//按奇偶排序数组
#include <stdio.h>
#include <stdlib.h>
#define LEN 10
int main()
{
    int arr[LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}; //数组的初始化
    int odd[LEN] = {0};                            //用来存储奇数
    int dou[LEN] = {0};                            //用来存储偶数
    int j = 0;
    int k = 0;
    for (int i = 0; i < LEN; i++)
    {
        if (arr[i] % 2)
        {
            odd[j] = arr[i];
            j++;
        }
        else
        {
            dou[k] = arr[i];
            k++;
        }
    }
    for (int i = 0; i < LEN; i++) //对目标数组的更改
    {
        if (i <= j)
        {
            arr[i] = odd[i];
        }
        else
        {
            arr[i] = dou[i - j - 1];
        }
    }
    for (int i = 0; i < LEN; i++)
    {
        printf("%d ", arr[i]);
    }
    system("pause");
    return 0;
}