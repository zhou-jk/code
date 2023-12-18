#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    char a[10002], b[10002];
    scanf("%s", a);
    scanf("%s", b);
    char s[10002], t[10002];
    int lens = 0, lent = 0;
    int lena = strlen(a), lenb = strlen(b);
    for (int i = 1; i < lena; i++)
        if (a[i] % 2 == a[i - 1] % 2)
            s[lens] = max(a[i], a[i - 1]), lens++;
    for (int i = 1; i < lenb; i++)
        if (b[i] % 2 == b[i - 1] % 2)
            t[lent] = max(b[i], b[i - 1]), lent++;
    s[lens] = t[lent] = '\0';
    if (strcmp(s, t) == 0)
        printf("%s", s);
    else
        printf("%s\n%s", s, t);
    return 0;
}