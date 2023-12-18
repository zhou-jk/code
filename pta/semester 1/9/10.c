#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000000];
    int cnt = 0;
    while (scanf("%s", s) != EOF)
    {
        cnt++;
        int len = strlen(s);
        printf("%d ", len);
    }
    if (cnt == 0)
        printf("0 ");
    return 0;
}