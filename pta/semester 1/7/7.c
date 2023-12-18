#include <stdio.h>
#include <string.h>

int main()
{
    char a[10002], b[10002];
    int vis[256] = {};
    fgets(a, sizeof(a), stdin);
    if (a[strlen(a) - 1] == '\n')
        a[strlen(a) - 1] = '\0';
    fgets(b, sizeof(b), stdin);
    if (b[strlen(b) - 1] == '\n')
        b[strlen(b) - 1] = '\0';
    int lena = strlen(a), lenb = strlen(b);
    for (int i = 0; i < lenb; i++)
        vis[(int)b[i]] = 1;
    for (int i = 0; i < lena; i++)
        if (!vis[(int)a[i]])
            printf("%c", a[i]);
    return 0;
}