//最长连续递增子序列
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[n], i;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int count = 0, max = 0, flag = 0, position = 0;
    for (i = 0; i < n; i++)
    {
        if (count == 0)
            count++;
        else if (count > 0)
        {
            if (a[i] > a[i - 1])
                count++;
            else
            {
                if (count > max)
                {
                    position = i - count;
                    max = count;
                }
                count = 0;
                i--;
            }
        }
        if (i == n - 1)
        {
            if (count > max)
            {
                position = i - count + 1;
                max = count;
            }
        }
    }
    printf("%d", a[position]);
    for (i = position + 1; i < position + max; i++)
        printf(" %d", a[i]);
    return 0;
}
