#include <stdio.h>

int main()
{
    int hh, mm, ss;
    scanf("%d:%d:%d", &hh, &mm, &ss);
    int n;
    scanf("%d", &n);
    ss += n;
    mm += ss / 60, ss %= 60;
    hh += mm / 60, mm %= 60;
    hh %= 24;
    printf("%02d:%02d:%02d", hh, mm, ss);
    return 0;
}