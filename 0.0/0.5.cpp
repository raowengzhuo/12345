#include<stdio.h>
int main(){
    int n,m;
    scanf("%d,%d",&n,&m);int max;
    if(m>n) max=m;else max=n;
    int k=0;
    for(int i=1;i<=max;i++){
        if(m%i==n%i){printf("%d和%d同余与%d\n",n,m,i);k=1;}
    }
    if(k==0)
    printf("不同余");
    return 0;
}