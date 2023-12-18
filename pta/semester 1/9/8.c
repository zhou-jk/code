#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[1000000];
    fgets(s, sizeof(s), stdin);
    int len = strlen(s);
    for (int i = 0; i < len; i++)
        if (isalpha(s[i]) && (i == 0 || s[i - 1] == ' '))
            s[i] = toupper(s[i]);
    printf("%s", s);
    return 0;
}