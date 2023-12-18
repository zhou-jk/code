#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int n;
    scanf("%d", &n);
    char s[82];
    fgets(s, sizeof(s), stdin);
    for (int t = 1; t <= n; t++)
    {
        fgets(s, sizeof(s), stdin);
        if (s[strlen(s) - 1] == '\n')
            s[strlen(s) - 1] = '\0';
        int len = strlen(s);

        int illegal = 0, alpha = 0, digit = 0;
        for (int i = 0; i < len; i++)
            if (isalpha(s[i]))
                alpha++;
            else if (isdigit(s[i]))
                digit++;
            else if (s[i] != '.')
                illegal++;
        if (len < 6)
            printf("Your password is tai duan le.\n");
        else if (illegal)
            printf("Your password is tai luan le.\n");
        else if (alpha > 0 && digit == 0)
            printf("Your password needs shu zi.\n");
        else if (alpha == 0 && digit > 0)
            printf("Your password needs zi mu.\n");
        else
            printf("Your password is wan mei.\n");
    }
    return 0;
}