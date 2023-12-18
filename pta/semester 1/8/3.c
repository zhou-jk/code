#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int ans = 0;
    int neg = 1;
    for (char ch = getchar(); ch != '#'; ch = getchar())
    {
        if (('0' <= ch && ch <= '9') || ('A' <= ch && ch <= 'F') || ('a' <= ch && ch <= 'f'))
        {
            if (neg == 1)
                neg = 0;
            if ('0' <= ch && ch <= '9')
                ans = ans * 16 + ch - '0';
            else if ('A' <= ch && ch <= 'F')
                ans = ans * 16 + ch - 'A' + 10;
            else
                ans = ans * 16 + ch - 'a' + 10;
        }
        else if (ch == '-' && neg == 1)
            neg = -1;
    }
    if (neg == -1)
        ans = -ans;
    printf("%d", ans);
    return 0;
}