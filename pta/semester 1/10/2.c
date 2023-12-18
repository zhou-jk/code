#include <stdio.h>
#include <string.h>
#include <ctype.h>

void stringDel(char *st)
{
    int i = 0, j = 0;
    int len = strlen(st);
    for (int i = 0; i < len; i++)
        if (!isalpha(st[i]))
        {
            if (i != j)
                j2i(st, j, i);
            j++;
        }
    if (j != len)
        j2i(st, j, len);
    return;
}