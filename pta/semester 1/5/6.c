#include <stdio.h>
#include <ctype.h>

int main()
{
    int letter = 0, blank = 0, digit = 0, other = 0;
    for (int i = 1; i <= 10; i++)
    {
        char ch = getchar();
        if (isalpha(ch))
            letter++;
        else if (ch == ' ' || ch == '\n')
            blank++;
        else if (isdigit(ch))
            digit++;
        else
            other++;
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d", letter, blank, digit, other);
    return 0;
}