#include<stdio.h>
int findPeak(int A[],int n)
{
    if (n < 3)
    {
        return -1;
    }
    int start = 1;
    int end = n - 2;
    while (start + 1 < end)
    {
        int middle = start + (end - start) / 2;
        if (A[middle] < A[middle - 1])
        {
            end = middle;
        }
        else if (A[middle] < A[middle + 1])
        {
            start = middle;
        }
        else
        {
            start = middle;
        }
    }
    if (A[start] > A[end])
    {
        return start;
    }
    return end;
};
int main(){
    int n;
    scanf("%d",&n);
    int m[n];
    for(int i=0;i<n;i++)
    scanf("%d",&m[i]);
    printf("%d",m[findPeak(m,n)]);
    return 0;
}
