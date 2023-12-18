#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int n;
    scanf("%d", &n);
    char s[2000002];
    fgets(s, sizeof(s), stdin);
    for (int t = 1; t <= n; t++)
    {
        fgets(s, sizeof(s), stdin);
        if (s[strlen(s) - 1] == '\n')
            s[strlen(s) - 1] = '\0';
        int len = strlen(s);
        int ok = 1;
        for (int i = 0; i < len - 1; i++)
            if ((isupper(s[i]) && (s[i + 1] != tolower(s[i]) && s[i + 1] != s[i] + 1)) || (islower(s[i]) && (s[i + 1] != toupper(s[i]) && s[i + 1] != s[i] - 1)))
            {
                ok = 0;
                break;
            }
        if (ok)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}