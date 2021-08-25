//数组顺序奇数在偶数前
#include<stdio.h>
bool isOdd(int n)
{
    return (n & 1) == 1;
}
int *exchange(int *nums, int numsSize)
{
    if ((nums == NULL) && (numsSize <= 0))
    {
        return NULL;
    }
    int *start = nums, *end = nums + numsSize - 1;
    while (start < end)
    {
        while ((start < end) && (isOdd(*start)))
        {
            start++;
        }
        while ((start < end) && (!isOdd(*end)))
        {
            end--;
        }
        if (start < end)
        {
            int temp = *start;
            *start = *end;
            *end = temp;
        }
    }
    return nums;
}
int main(){
    int n;
    scanf("%d",&n);int m[n];
    for(int i=0;i<n;i++)scanf("%d",&m[i]);
    exchange(m,n);
    for(int i=0;i<n;i++)printf("%d ",m[i]);
    return 0;
}