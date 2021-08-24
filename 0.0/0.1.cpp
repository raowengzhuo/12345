#include <stdio.h>
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int k = 0;
    k = m;
    if (m < n)
    {

        m = n;
        n = k;
    }
    int l;
    while (k != 0)
    {
        l = n;     //上一级余数
        k = m % n; //现在的余数
        m = n;
        n = k;
    }
    printf("最大公约数为：%d\n", l);
    return 0;
} //测试样例：1997 615 公约数：1