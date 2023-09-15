#include <stdio.h>

void splitfloat(float x, int *intpart, float *fracpart)
{
    *intpart = (int)x;
    *fracpart = x - *intpart;
    return;
}