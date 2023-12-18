#include <stdio.h>
#include <string.h>

int main()
{
    char s[1002];
    scanf("%s", s);
    int len = strlen(s);
    int c[10] = {};
    for (int i = 0; i < len; i++)
        c[s[i] - '0']++;
    for (int i = 0; i <= 9; i++)
        if (c[i] > 0)
            printf("%d:%d\n", i, c[i]);
    return 0;
}