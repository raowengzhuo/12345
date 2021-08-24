#include <stdio.h>
int main()
{
    double x1, y1, x2, y2, x3, y3;
    scanf("%lf,%lf,%lf,%lf,%lf,%lf",&x1,&y1,&x2,&y2,&x3,&y3);
        double ans = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1); //表示向量AB与AC的叉积的结果
        if (ans > 0)
            printf("逆时针\n");
        if (ans < 0)
            printf("顺时针\n");
        if (ans == 0)
            printf("共线\n");
    return 0;
}