#include <stdio.h>

int reverse(int number)
{
    int res = 0;
    int negative = 0;
    if (number < 0)
        number = -number, negative = 1;
    while (number)
        res = res * 10 + number % 10, number /= 10;
    if (negative)
        res = -res;
    return res;
}