#include <stdio.h>

int main()
{
    int points;
    scanf("%d", &points);
    if (points >= 90)
        printf("gong xi ni kao le %d fen!", points);
    else
        printf("kao le %d fen bie xie qi!", points);
    return 0;
}