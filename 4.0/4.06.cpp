///第一个只出现一次的字符
#include <stdio.h>
#include <string.h>
int main()
{
    char a[100000];
    int c[100000] = {0}; //存放每个字符出现的次数，初始时全为0
    gets(a);
    for (int i = 0; i < strlen(a); i++) //遍历字符串中每一个字符
    {
        for (int j = 0; j < strlen(a); j++) //遍历第二次让a[j]和a[i]对比
        {
            if (a[i] == a[j])
                c[i]++; //如果相同c[i]++
        }
        if (c[i] == 1)
        {
            printf("%c\n", a[i]);
            return 0;
        }
    }
    printf("no\n");
    return 0;
}
