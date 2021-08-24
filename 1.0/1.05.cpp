//数字在排序数组中出现的次数
#include <stdio.h>
int One_Num_Times(int *arr, int len, int num)
{
    int i = 0;
    int times = 0;
    for (i = 0; i < len && num >= *arr; i++, arr++)
    {
        if (*arr == num)
        {
            times++;
        }
    }
    return times;
}
int main()
{
    int n,m;
    scanf("%d,%d",&n,&m);
    int arr[n];
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    printf("%d在数组中出现了%d次\n",m, One_Num_Times(arr, sizeof(arr) / sizeof(arr[0]), m));
    return 0;
}