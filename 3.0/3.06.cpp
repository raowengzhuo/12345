//归并排序
#include <stdio.h>
#define ArrLen 20
void printList(int arr[], int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d\t", arr[i]);
    }
}
void merge(int arr[], int start, int mid, int end)
{
    int result[ArrLen];
    int k = 0;
    int i = start;
    int j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            result[k++] = arr[i++];
        }
        else
        {
            result[k++] = arr[j++];
        }
    }
    if (i == mid + 1)
    {
        while (j <= end)
            result[k++] = arr[j++];
    }
    if (j == end + 1)
    {
        while (i <= mid)
            result[k++] = arr[i++];
    }
    for (j = 0, i = start; j < k; i++, j++)
    {
        arr[i] = result[j];
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main()
{
    int n;scanf("%d",&n);int arr[n];
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    mergeSort(arr, 0, n-1);
    printList(arr, n);
    return 0;
}