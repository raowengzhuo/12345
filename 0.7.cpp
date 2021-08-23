#include<stdio.h>
#include<math.h>
int main(){
    int m,n,l;
    scanf("%d,%d,%d",&m,&n,&l);
    double c=1.0*(m+n+l)/2;
    double sum=c*(c-m)*(c-n)*(c-l);
    double s=sqrt(sum);
    printf("%.2lf",s);
    return 0;
}