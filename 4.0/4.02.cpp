//反转字符串
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str = "i love you";
    char strrev1[10];
    int i, length;
    i = 0;
    length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    printf("字符串长度：%d", length); //可用<string.h>中的strlen代替
    printf("原字符串：%s\n", str);
    while (length >= 0)
    {
        strrev1[i++] = str[--length];
    }
    printf("反转后字符串：%s\n", strrev1);
    system("pause");
}