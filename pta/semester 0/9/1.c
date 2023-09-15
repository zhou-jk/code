#include <stdio.h>
#include <string.h>

int main()
{
    char s[82];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';
    int n = strlen(s);
    int cnt[128];
    for (int i = 0; i < 128; i++)
        cnt[i] = 0;
    for (int i = 0; i < n; i++)
        cnt[(int)s[i]] = 1;
    for (int i = 0; i < 128; i++)
        if (cnt[i])
            printf("%c", (char)i);
    return 0;
}