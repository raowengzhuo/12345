#include<stdio.h>
#include<math.h>
bool use[11];
const int factorial[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800}; //阶乘0-9
int decantor(int X,int n){
    int ans=0;//存放答案
    int sum=0;//暂时计数
    int q=0;int r=0;
    for(int i=n-1;i>=1;i--){
        q=X/factorial[i];
        r=X%factorial[i];
        for(int j=1;j<=n;j++){
            if(!use[j])sum++;
            if(sum==q+1){
                ans+=j*pow(10,i);
                sum=0;
                X=r;
                use[j]=true;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!use[i])
        {
            ans += i;
            break;
        }
    }           //最后一位
    return ans; //答案
}
int main(){
    int n,x;scanf("%d,%d",&n,&x);//数的个数,位置
    for(int i=1;i<=10;i++)use[i]=false;
    printf("%d\n",decantor(x-1,n));    
    return 0;
}