//选择排序
#include <stdio.h>
int main(void)
{
    int a[1001];
    int n, i, j, t;
    scanf("%d", &n); //n为要排序的数的个数
    //输入需要排序的数
    for (i = 0; i < n; ++i)
        scanf("%d", a + i);
    //接下来进行排序
    for (i = 0; i < n - 1; ++i) //因为每次需要和a[i]后面的数进行比较,所以到a[n-2](倒数第2个元素)就行
    {
        for (j = i + 1; j < n; ++j) //j从i后一个开始,a[i]与a[j]进行比较
        {
            if (a[i] > a[j]) //a[i]为当前值,若是比后面的a[j]大,进行交换
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        } //每排序一次,就会将a[i](包括a[i])之后的最小值放在a[i]的位置
        for (j = 0; j < n; ++j)
            printf("%-5d", a[j]);
        printf("\n\n");
    }

    return 0;
}