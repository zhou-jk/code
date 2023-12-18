#include <stdio.h>
#include <ctype.h>

int main()
{
    for (char ch = getchar(); ch != '#'; ch = getchar())
        if (islower(ch))
            printf("%c", toupper(ch));
        else if (isupper(ch))
            printf("%c", tolower(ch));
        else
            printf("%c", ch);
    return 0;
}