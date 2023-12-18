#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int cmp(char *a, char *b)
{
    int lena = strlen(a), lenb = strlen(b);
    int len = min(lena, lenb);
    for (int i = 0; i < len; i++)
        if (a[i] < b[i])
            return 1;
        else if (a[i] > b[i])
            return 0;
    return lena < lenb;
}

int main()
{
    char s[5][82];
    char *t[5];
    int n = 5;
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
    for (int i = 0; i < n; i++)
        t[i] = s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j + 1 < n; j++)
            if (!cmp(t[j], t[j + 1]))
            {
                char *tmp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = tmp;
            }
    printf("After sorted:\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", t[i]);
    return 0;
}