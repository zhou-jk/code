#include <stdio.h>

int main()
{
    double eps;
    scanf("%le", &eps);
    double pi = 1;
    double fac = 1;
    for (int i = 1; fac >= eps; i++)
    {
        fac = fac * i / (2 * i + 1);
        pi += fac;
    }
    pi *= 2;
    printf("PI = %.5lf", pi);
    return 0;
}