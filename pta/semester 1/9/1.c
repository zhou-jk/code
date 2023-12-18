#include <stdio.h>

int reverse(int number)
{
    int flag = 0;
    if (number < 0)
        flag = 1, number = -number;
    int res = 0;
    while (number)
        res = res * 10 + number % 10, number /= 10;
    if (flag)
        res = -res;
    return res;
}