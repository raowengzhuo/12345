//重排链表
#include <stdio.h>
struct nod
{
    int id, data, next;
} a[100000], b[100000];
int main()
{
    int n1, n, i, j = 0, head, temp[100000];
    scanf("%d%d", &head, &n);
    n1 = n;
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d", &a[i].id, &a[i].data, &a[i].next);
    }
    while (n--)
    {
        for (i = 0; i < n1; i++)
        {
            if (a[i].id == head)
            {
                b[j].id = a[i].id;
                b[j].data = a[i].data;
                //	b[i].next=a[i].next;
                temp[j] = a[i].next;
                j++;
                break;
            }
        }
        head = temp[j - 1];
    }
    for (i = 0; i < j / 2; i++)
    {
        printf("%05d %d %05d\n", b[j - i - 1].id, b[j - i - 1].data, b[i].id);
        if (i != (j / 2 - 1))
            printf("%05d %d %05d\n", b[i].id, b[i].data, b[j - i - 2].id);
        else if (j % 2 == 0)
            printf("%05d %d -1\n", b[i].id, b[i].data);
        else
        {
            printf("%05d %d %05d\n", b[i].id, b[i].data, b[j - i - 2].id);
            printf("%05d %d -1\n", b[i + 1].id, b[i + 1].data);
        }
    }
}
