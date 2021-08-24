//两数之后
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int *twoSum(int *nums, int numsSize, int target)
{
    assert(nums);
    for (int i = 0; i < numsSize - 1; i++) //第一层循环从数组开头开始遍历nums[i] 开始i=0
    {
        for (int j = i + 1; j < numsSize; j++) //第二层循环nums[i+1]下一个元素
        {
            if (nums[i] + nums[j] == target) //满足题中给出条件即返回
            {
                int *p = (int *)malloc(2 * sizeof(int));
                p[0] = i;
                p[1] = j;
                return p;
            }
        }
    }
    return NULL;
}
int main()
{
    int n;
    scanf("%d",&n);
    int nums[n];
    for(int i=0;i<n;i++)scanf("%d",&nums[i]);
    int target;scanf("%d",&target);
    int *p = twoSum(nums, n, target);
    if (p != NULL)
    {
        printf("%d ", nums[p[0]]);
        printf("%d \n", nums[p[1]]);
    }
    free(p);
    p = NULL;
    return 0;
}