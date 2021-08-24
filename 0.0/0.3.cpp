#include<stdio.h>
#include<stdlib.h>
const int factorial[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800}; //阶乘0-10
int cantor(int a[], int n)//cantor展开,n表示是n位的全排列，a[]表示全排列的数（用数组表示）
{ 
    int ans = 0, sum = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
            if (a[j] < a[i])
                sum++;
        ans += sum * factorial[n - i]; //累积
        sum = 0;                       //计数器归零
    }
    return ans + 1;
}
int main(){
    int n;
    scanf("%d",&n);
    int m[n+1];
    for(int i=1;i<=n;i++){
        scanf("%d",&m[i]);
    }
    printf("%d\n", cantor(m,n));
    return 0;
}