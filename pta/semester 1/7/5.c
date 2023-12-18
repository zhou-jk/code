#include <stdio.h>
#include <string.h>

int main()
{
    char s[500001];
    char t[500001];
    int n = 0;
    while (scanf("%s", s) != EOF)
    {
        int len = strlen(s);
        for (int i = 0; i < len; i++)
            t[n++] = s[i];
        t[n++] = ' ';
    }
    for (int i = n - 2, j = n - 2; i >= 0; i = j)
    {
        while (j >= 0 && t[j] != ' ')
            j--;
        if (i != n - 2)
            printf(" ");
        for (int k = j + 1; k <= i; k++)
            printf("%c", t[k]);
        j--;
    }
    return 0;
}