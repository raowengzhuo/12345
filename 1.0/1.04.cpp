#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Interval
{
    int start;
    int end;
};

int cmp(const void *a, const void *b)
{
    return ((struct Interval *)a)->start - ((struct Interval *)b)->start;
}

struct Interval *merge(struct Interval *intervals, int intervalsLen, int *returnSize)
{
    struct Interval *result = (struct Interval *)malloc(intervalsLen * sizeof(struct Interval));
    int i = 0, k = 0;
    int flag[intervalsLen];
    memset(flag, 0, sizeof(flag));
    qsort(intervals, intervalsLen, sizeof(struct Interval), cmp);

    for (i = 0; i < intervalsLen - 1; i++)
    {
        if (intervals[i + 1].start <= intervals[i].end)
        {
            intervals[i + 1].start = intervals[i].start;
            intervals[i + 1].end = (intervals[i].end > intervals[i + 1].end ? intervals[i].end : intervals[i + 1].end);
            flag[i] = 1;
        }
    }
    for (i = 0; i < intervalsLen; i++)
    {
        if (flag[i] == 1)
            continue;
        result[k++] = intervals[i];
    }
    *returnSize = k;
    return result;
}

int main()
{
    /*
	example 1：{10,30},{20,60},{80,100},{150,180}   result:[10,60],[80,100],[150,180]
	example 2：{10,20},{20,60},{60,100},{100,180}   result:[10,180]
	example 3：{10,20},{30,60},{50,100},{20,180}    result:[10,180]
	*/
    int n;
    scanf("%d",&n);
    struct Interval intervals[n];
    for(int i=0;i<n;i++)scanf("%d,%d",&intervals[i].start,&intervals[i].end);
    int returnSize;
    int i = 0;
    struct Interval *result = merge(intervals, 4, &returnSize);
    for (i = 0; i < returnSize - 1; i++)
    {
        printf("[%d,%d],", result[i].start, result[i].end);
    }
    printf("[%d,%d]\n", result[returnSize - 1].start, result[returnSize - 1].end);
    free(result);
    result = NULL;
    return 0;
}
