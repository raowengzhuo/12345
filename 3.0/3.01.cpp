//冒泡排序
#include <stdio.h>
int main(void)
{
    int a[1001];
    int n, i, j, t;
    scanf("%d", &n); //n为要排序的数的个数
    //输入要排序的数
    for (i = 0; i < n; ++i)
        scanf("%d", a + i);

    //接下来进行排序
    for (i = 0; i < n - 1; ++i) //n个数,总共需要进行n-1次
    {                           //n-1个数排完,第一个数一定已经归位
        //每次会将最大(升序)或最小(降序)放到最后面
        for (j = 0; j < n - i - 1; ++j)
        {
            if (a[j] > a[j + 1]) //每次冒泡,进行交换
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
        for (j = 0; j < n; ++j)
            printf("%-5d ", a[j]);
        printf("\n\n");
    }

    return 0;
}