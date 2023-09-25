#include <stdio.h>

int main()
{
    int speed, limit;
    scanf("%d%d", &speed, &limit);
    double percentage = (speed - limit) * 100.0 / limit;
    if (percentage >= 50)
        printf("Exceed %.0lf%%. License Revoked", percentage);
    else if (percentage >= 10)
        printf("Exceed %.0lf%%. Ticket 200", percentage);
    else
        printf("OK");
    return 0;
}