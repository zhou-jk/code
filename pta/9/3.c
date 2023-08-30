#include <stdio.h>
#include <string.h>

int main()
{
    char a[10002], b[10002];
    fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\n")] = '\0';
    fgets(b, sizeof(b), stdin);
    b[strcspn(b, "\n")] = '\0';
    int n = strlen(a), m = strlen(b);
    int book[128];
    for (int i = 0; i < 128; i++)
        book[i] = 0;
    for (int i = 0; i < m; i++)
        book[(int)b[i]] = 1;
    for (int i = 0; i < n; i++)
        if (!book[(int)a[i]])
            printf("%c", a[i]);
    return 0;
}