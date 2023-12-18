#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    char ch;
    while ((ch = getchar()) != '=')
    {
        int b;
        scanf("%d", &b);
        if ((ch == '/') && (b == 0))
        {
            printf("ERROR");
            return 0;
        }
        if (ch == '+')
            a += b;
        else if (ch == '-')
            a -= b;
        else if (ch == '*')
            a *= b;
        else if (ch == '/')
            a /= b;
        else
        {
            printf("ERROR");
            return 0;
        }
    }
    printf("%d", a);
    return 0;
}