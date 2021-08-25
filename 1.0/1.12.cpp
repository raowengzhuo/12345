//缺失数字
#include<stdio.h>
int missingNumber(int *nums, int numsSize)
{
    int sum_all = numsSize * (numsSize + 1) / 2;
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
    }
    return sum_all - sum;
}
int main(){
    int n;
    scanf("%d",&n);
    int m[n];
    for(int i=0;i<n;i++)
    scanf("%d",&m[i]);
    printf("%d",missingNumber(m,n));
    return 0;
}
