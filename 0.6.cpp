#include<stdio.h>
#include<math.h>
#define M 10003

int PowMod(long long int n, long long int p)
{
    if (p == 1)
    {
        return n % M;
    }
    int temp = PowMod(n, p / 2);
    int result = (temp * temp) % M;
    if (p % 2 == 1)
    {
        result = (result * n) % M;
    }
    return result;
}
int main(){
    long long int n,p;
    scanf("%lld,%lld",&n,&p);
    printf("%lld",PowMod(n,p));
    return 0;
}