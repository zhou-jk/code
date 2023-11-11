#include <stdio.h>

int MonthDays(int year, int month)
{
    int dates[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
        dates[2] = 29;
    return dates[month];
}