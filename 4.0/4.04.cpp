//最长公共前缀
#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    char strs1[200] = {0};
    char strs2[200] = {0};
    char strs3[200] = {0};
    gets(strs1);
    gets(strs2);
    gets(strs3);
    int len1 = strlen(strs1);
    int len2 = strlen(strs2);
    int len3 = strlen(strs3);
    int len = fmin(fmin(len1, len2), len3);
    if ((strs1[0] != strs2[0]) || (strs1[0] != strs3[0]) || (strs3[0] != strs2[0]))
    {
        printf("");
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            if ((strs1[i] == strs2[i]) && (strs1[i] == strs3[i]) && (strs3[i] == strs2[i]))
            {
                printf("%c", strs1[i]);
            }
            else
            {
                break;
            }
        }
    }
}