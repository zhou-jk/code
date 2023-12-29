#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "sort.h"

bool is_sorted(int a[], int n)
{
    for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            return false;
    return true;
}

void generate(int *a, int *b, int n)
{
    for (int i = 0; i < n; i++)
        a[i] = b[i] = rand();
    stdlib_sort(b, n);
    int times = 10;
    for (int i = 1; i <= times; i++)
    {
        int l = rand() % n, r = rand() % n;
        while (l == r)
            l = rand() % n, r = rand() % n;
        int t = b[l];
        b[l] = b[r];
        b[r] = t;
    }
    return;
}

void test(int a[], int n, void (*sort)(int *, int), const char type[], const char name[])
{
    int *c = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        c[i] = a[i];
    int st = clock();
    sort(c, n);
    int ed = clock();
    double time = (double)(ed - st) / CLOCKS_PER_SEC;
    printf("%20s | %25s | time: %.10lf\n", type, name, time);
    if (!is_sorted(c, n))
    {
        fprintf(stderr, "Error\n");
        exit(1);
    }
    free(c);
    return;
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Need more parameters");
        return 1;
    }
    int n = atoi(argv[1]), seed = atoi(argv[2]);
    printf("n = %d, seed = %d\n", n, seed);
    srand(seed);
    int *a = (int *)malloc(sizeof(int) * n), *b = (int *)malloc(sizeof(int) * n);
    generate(a, b, n);
    //test(a, n, bubble_sort, "Bubble Sort", "Random Sequence");
    //test(b, n, bubble_sort, "Bubble Sort", "Almost Ordered Sequence");
    test(a, n, selection_sort, "Selection Sort", "Random Sequence");
    test(b, n, selection_sort, "Selection Sort", "Almost Ordered Sequence");
    test(a, n, insertion_sort, "Insertion Sort", "Random Sequence");
    test(b, n, insertion_sort, "Insertion Sort", "Almost Ordered Sequence");
    test(a, n, merge_sort, "Merge Sort", "Random Sequence");
    test(b, n, merge_sort, "Merge Sort", "Almost Ordered Sequence");
    test(a, n, quick_sort, "Quick Sort", "Random Sequence");
    test(b, n, quick_sort, "Quick Sort", "Almost Ordered Sequence");
    test(a, n, radix_sort, "Radix Sort", "Random Sequence");
    test(b, n, radix_sort, "Radix Sort", "Almost Ordered Sequence");
    test(a, n, stdlib_sort, "Stdlib Sort", "Random Sequence");
    test(b, n, stdlib_sort, "Stdlib Sort", "Almost Ordered Sequence");
    return 0;
}