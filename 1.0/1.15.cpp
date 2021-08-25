//子数组最大乘积
#include<stdio.h>
int maxProduct(int *nums, int numsSize)
{
    int max = 0;
    int max_temp = 1;
    int min_temp = 1;
    int i;
    int temp;

    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] < 0)
        {
            temp = max_temp;
            max_temp = min_temp;
            min_temp = temp;
        }

        max_temp = (max_temp * nums[i] > nums[i] ? max_temp * nums[i] : nums[i]);
        min_temp = (min_temp * nums[i] < nums[i] ? min_temp * nums[i] : nums[i]);

        max = (max_temp > max ? max_temp : max);
    }

    return max;
}
int main()
{
    int n;
    scanf("%d", &n);
    int m[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &m[i]);
    printf("%d", maxProduct(m,n));
    return 0;
}
