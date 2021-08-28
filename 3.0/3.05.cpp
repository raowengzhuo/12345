//二分查找
#include <stdio.h>

int binarySearch(int a[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midVal = a[mid];
        if (midVal < key)
            low = mid + 1;
        else if (midVal > key)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
};

int main()
{
    int i, val, ret,n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for (i = 0; i < 8; i++)
        printf("%d\t", a[i]);

    printf("\n请输人所要查找的元素：");
    scanf("%d", &val);

    ret = binarySearch(a, 8, val);

    if (-1 == ret)
        printf("查找失败 \n");
    else
        printf("查找成功 \n");

    return 0;
}