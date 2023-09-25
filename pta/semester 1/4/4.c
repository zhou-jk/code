#include <stdio.h>

int main()
{
    int sth, stm, edh, edm;
    scanf("%2d%2d %2d%2d", &sth, &stm, &edh, &edm);
    int hh = edh - sth, mm = edm - stm;
    if (mm < 0)
        mm += 60, hh--;
    printf("%02d:%02d", hh, mm);
    return 0;
}