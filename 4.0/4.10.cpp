//字符串排序
#include <stdio.h>
#include <string.h>
void sort(char c[][81], int n)
{
    int i, j, k;
    char t[81];
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
            if (strcmp(c[k], c[j]) > 0)
                k = j;
        if (k != i)
        {
            strcpy(t, c[i]);
            strcpy(c[i], c[k]);
            strcpy(c[k], t);
        }
    }
}

int main()
{
    int i;
    char c[5][81] = {0};
    for (i = 0; i < 5; i++)
        scanf("%s", c[i]);
    sort(c, 5);
    printf("After sorted:\n");
    for (i = 0; i < 5; i++)
        printf("%s\n", c[i]);
    return 0;
}
