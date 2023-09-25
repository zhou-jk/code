#include <stdio.h>
#include <math.h>

int main()
{
    int money, year;
    double rate;
    scanf("%d%d%lf", &money, &year, &rate);
    double sum = money * pow(1 + rate, year);
    printf("sum = %.2lf", sum);
    return 0;
}