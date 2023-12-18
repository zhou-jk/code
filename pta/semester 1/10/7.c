#include <stdio.h>
#include <string.h>

int main()
{
    char s[1002];
    fgets(s, sizeof(s), stdin);
    int len = strlen(s);

    for (int i = 0; i < len; i++)
        if (s[i] == '6')
        {
            int j = i;
            while (j < len && s[j] == '6')
                j++;
            if (j - i > 9)
                printf("27");
            else if (j - i > 3)
                printf("9");
            else
            {
                for (int k = i; k < j; k++)
                    printf("6");
            }
            i = j - 1;
        }
        else
            printf("%c", s[i]);
    return 0;
}