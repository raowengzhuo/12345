#include <stdio.h>
void delect(int i, int m[], int n);
int main()
{
    int n;
    scanf("%d", &n);
    int m[n + 1];
    for (int i = 0; i <= n; i++)
    {
        m[i] = i;
    }
    delect(0, m, n);
    n--;
    delect(0, m, n);
    n--;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (m[j] % m[i] == 0)
            {
                delect(j, m, n);
                n--;
            }
        }
    }
    for (int i = 0; i <= n; i++)
        printf("%d ", m[i]);
    return 0;
}
void delect(int i, int m[], int n)
{
    for (int j = i; j <= n; j++)
    {
        m[j] = m[j + 1];
    }
    m[n] = 0;
}