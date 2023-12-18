#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = 0;
    int qx[n * n], qy[n * n];
    int head = 0, tail = -1;
    tail++, qx[tail] = 0, qy[tail] = n / 2;
    a[qx[tail]][qy[tail]] = 1;
    while (head <= tail)
    {
        int x = qx[head], y = qy[head];
        head++;
        if (a[x][y] == n * n)
            break;
        int tx = (x - 1 + n) % n, ty = (y + 1) % n;
        if (a[tx][ty] != 0)
            tx = (x + 1) % n, ty = y;
        a[tx][ty] = a[x][y] + 1;
        tail++, qx[tail] = tx, qy[tail] = ty;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}