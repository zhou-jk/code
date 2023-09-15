#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void sort(int a[], int n)
{
    qsort(a, n, sizeof(int), compare);
}