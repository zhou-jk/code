#include <stdio.h>

int main()
{
    int n = 10;
    int a[10];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int k;
    scanf("%d", &k);
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == k)
            cnt++;
    printf("%d", cnt);
    return 0;
}