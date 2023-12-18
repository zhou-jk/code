#include <stdio.h>
#include <ctype.h>

void string2words(char *Chars)
{
    for (int i = 0, j = 0; Chars[i] != '\0'; i = j)
    {
        while (Chars[i] != '\0' && !isalpha(Chars[i]))
            i++;
        j = i;
        while (Chars[j] != '\0' && isalpha(Chars[j]))
            j++;
        if (i < j)
        {
            printf("[");
            for (int k = i; k < j; k++)
                printf("%c", Chars[k]);
            printf("]");
        }
    }
    return;
}