//数组中出现次数超过一半的数字
#include<stdio.h>
int majorityElement(int *nums, int numsSize)
{
    int x = 0;
    int vote = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if (vote == 0)
        {
            x = nums[i];
            vote++;
        }
        else if (x == nums[i])
        {
            vote++;
        }
        else
        {
            vote--;
        }
    }
    return x;
}
int main(){
    int n;
    scanf("%d",&n);
    int m[n];
    for(int i=0;i<n;i++)scanf("%d",&m[i]);
    printf("%d",majorityElement(m,n));
    return 0;
}