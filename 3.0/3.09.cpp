//车厢重组
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int i, j;
    scanf("\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int sum = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                sum++;
            }
        }
    }
    printf("%d", sum);
    return 0;
}
