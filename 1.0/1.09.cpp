//在两个长度相等的排序数组中找到上中位数
#include<stdio.h>
int findMedianinTwoSortedAray(int *arr1, int arr1Len, int *arr2, int arr2Len)
{
    int k = 0;
    int i = 0, j = 0;

    while (k < arr1Len)
    {
        while (arr1[i] < arr2[j])
        {
            if (k == arr1Len - 1)
                return arr1[i];
            i++;
            k++;
        }
        while (arr1[i] >= arr2[j])
        {
            if (k == arr1Len - 1)
                return arr2[j];
            j++;
            k++;
        }
    }
    return 0;
}
int main(){
    int n1,n2;
    scanf("%d,%d",&n1,&n2);
    int m1[n1],m2[n2];
    for(int i=0;i<n1;i++)scanf("%d",&m1[i]);
    for(int i=0;i<n2;i++)scanf("%d",&m2[i]);
    printf("%d",findMedianinTwoSortedAray(m1,n1,m2,n2));
    return 0;
}