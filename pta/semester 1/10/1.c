#include <stdio.h>

void delchar(char *str, char c)
{
    int i = 0, j = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != c)
            str[j++] = str[i];
    str[j] = '\0';
    return;
}