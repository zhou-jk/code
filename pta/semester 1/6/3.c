#include <stdio.h>
#include <string.h>

int main()
{
    char s[81];
    fgets(s, sizeof(s), stdin);
    char ch;
    scanf("%c", &ch);
    int len = strlen(s);
    int cnt = 0;
    for (int i = 0; i < len; i++)
        if (s[i] == ch)
            cnt++;
    printf("%d", cnt);
    return 0;
}