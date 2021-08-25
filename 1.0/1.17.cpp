//求集合的所有子集 
#include <stdio.h>
#include <stdlib.h>

//整形数组arr,arr长度为len
void AllSubsets(int *arr, int len)
{
    int i, j, k;
    int num = 1 << len; //1左移len位,即乘以2^len,num=2^len个子集
    for (i = 0; i < num; i++)
    {
        j = i;
        k = 0;
        printf("{");
        while (j)
        {
            //j的二进制与0001按位与，输出不为0则打印
            //和0001按位与意思是判断最右边是否为1
            if (j & 1)
            {
                printf("%d", arr[k]);
            }
            j >>= 1; //j右移一位，即/2，0011变为0001，意思是从右往左遍历每一位，为1则输出为0则不输出
            k++;
        }
        printf("}\n");
    }
}

int main()
{
    int b = 0;
    scanf("%d", &b);
    int arr[b];
    for (int i = 0; i < b; i++)
    {
        scanf("%d", &arr[i]);
    }
    int len = sizeof(arr) / sizeof(arr[0]);
    AllSubsets(arr, len);
}
