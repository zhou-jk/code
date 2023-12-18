#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch;
    while ((ch = getchar()) != '\n')
    {
        if (islower(ch))
        {
            if (ch == 'z')
                ch = 'A';
            else
                ch = toupper(ch + 1);
        }
        else if (isupper(ch))
        {
            if (ch == 'Z')
                ch = 'a';
            else
                ch = tolower(ch + 1);
        }
        putchar(ch);
    }
    putchar('\n');
    return 0;
}