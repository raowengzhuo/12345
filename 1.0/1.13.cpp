//股票
#include<stdio.h>
#include<math.h>
int maxProfit(int *prices, int pricesSize)
{
    if (NULL == prices || pricesSize <= 1)
        return 0;
    //申请一个priceSize行两列的二维数组
    int **dp = (int **)malloc(sizeof(int) * pricesSize);
    for (int i = 0; i < pricesSize; ++i)
    {
        dp[i] = (int *)malloc(sizeof(int) * 2);
    }
    //初始化
    dp[0][0] = prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < pricesSize; ++i)
    {
        dp[i][0] = fmin(dp[i - 1][0], prices[i]);
        dp[i][1] = fmax(dp[i - 1][1], prices[i] - dp[i][0]);
    }
    int res = dp[pricesSize - 1][1];     //将结果赋值到res再返回
    for (int i = 0; i < pricesSize; ++i) //释放内存
    {
        free(dp[i]);
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    int m[n];
    for(int i=0;i<n;i++)scanf("%d",&m[i]);
    printf("%d",maxProfit(m,n));
    return 0;
}