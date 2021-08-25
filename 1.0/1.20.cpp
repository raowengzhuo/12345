//矩阵乘法
#include <stdio.h>
int main()
{
    int m,n,l;
    scanf("%d,%d,%d",&m,&n,&l);
    int a[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    int b[n][l];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < l; j++)
            scanf("%d", &b[i][j]);
    int c[m][l];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < 2; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }

    printf("矩阵1与矩阵2相乘的结果为:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}