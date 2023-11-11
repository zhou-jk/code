#include <stdio.h>

int get_weekday(int year, int month, int day)
{
    return (day + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5) + (365 * (year + 4800 - ((14 - month) / 12))) + ((year + 4800 - ((14 - month) / 12)) / 4) - ((year + 4800 - ((14 - month) / 12)) / 100) + ((year + 4800 - ((14 - month) / 12)) / 400) - 32045) % 7;
}
const char *weekday[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
int main()
{
    int year, month, day;
    scanf("%d/%d/%d", &year, &month, &day);
    printf("%s", weekday[get_weekday(year, month, day)]);
    return 0;
}