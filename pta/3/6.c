#include <stdio.h>

int main()
{
    char ch;
    scanf("%c", &ch);
    if (ch == 'A')
        printf("[90-100]");
    else if (ch == 'B')
        printf("[80-90)");
    else if (ch == 'C')
        printf("[70-80)");
    else if (ch == 'D')
        printf("[60-70)");
    else if (ch == 'E')
        printf("[0-60)");
    else
        printf("ERROR");
    return 0;
}