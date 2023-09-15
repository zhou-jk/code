#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int n;
    scanf("%d", &n);
    char s[82];
    fgets(s, sizeof(s), stdin);
    for (int t = 0; t < n; t++)
    {
        fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n")] = '\0';
        int m = strlen(s);
        if (m < 6)
            printf("Your password is tai duan le.\n");
        else
        {
            int hasdigit = 0, hasalpha = 0, hasillegal = 0;
            for (int i = 0; i < m; i++)
                if (isdigit(s[i]))
                    hasdigit = 1;
                else if (isalpha(s[i]))
                    hasalpha = 1;
                else if (s[i] != '.')
                    hasillegal = 1;
            if (hasdigit && hasalpha && !hasillegal)
                printf("Your password is wan mei.\n");
            else if (hasillegal)
                printf("Your password is tai luan le.\n");
            else if (!hasdigit)
                printf("Your password needs shu zi.\n");
            else if (!hasalpha)
                printf("Your password needs zi mu.\n");
        }
    }
    return 0;
}