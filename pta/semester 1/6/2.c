#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[81];
    fgets(s, sizeof(s), stdin);
    int len = strlen(s);
    int cnt = 0;
    for (int i = 0; i < len; i++)
        if (isupper(s[i]) && s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U')
            cnt++;
    printf("%d", cnt);
    return 0;
}