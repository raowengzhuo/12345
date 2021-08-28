//排座位号
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, m, i, j, x = 65;
    while (~scanf("%d %d", &n, &m) && x)
        /*&&与  、||或  、~按位取反运算*/
        {
            int a[100][100], count = 1;
            i = j = 0;
            for (j = 1; j <= m; j++) //  j控制列
            {
                if (i == 0)
                {
                    for (i = 1; i <= n; i++) //   i控制行
                    {
                        a[i][j] = count++;
                    }
                }
                else
                    // 逆运算  将 i=3 减到 0 ；
                    {
                        for (i = n; i >= 1; i--)
                        {
                            a[i][j] = count++;
                        }
                    }
            }
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= m; j++)
                {
                    if (j == m)
                        printf("%02d\n", a[i][j]); //  当j = 3时，换行输出结果
                    else
                        printf("%02d ", a[i][j]);
                }
            }
            x--; //题目要求不超过65
        }
    return 0;
}
