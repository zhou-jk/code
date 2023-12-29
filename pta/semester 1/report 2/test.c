#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct
{
    int start, end;
} Range;

void quick_sort_stack(int a[], const int n)
{
    if (n <= 0)
        return;
    Range *r = (Range *)malloc(sizeof(Range) * n);
    int p = 0;
    r[p++] = (Range){0, n - 1};
    while (p)
    {
        Range range = r[--p];
        int len = range.end - range.start + 1;
        int pivot = a[rand() % len + range.start];
        int i = range.start, j = range.start, k = range.end;
        while (i <= k)
        {
            if (a[i] < pivot)
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
                i++, j++;
            }
            else if (pivot < a[i])
            {
                int t = a[i];
                a[i] = a[k];
                a[k] = t;
                k--;
            }
            else
                i++;
        }
        if (range.start < j - 1)
            r[p++] = (Range){range.start, j - 1};
        if (k + 1 < range.end)
            r[p++] = (Range){k + 1, range.end};
    }
    free(r);
    return;
}

void quick_sort(int a[], const int n)
{
    if (n <= 1)
        return;
    int pivot = a[rand() % n];
    int i = 0, j = 0, k = n;
    while (i < k)
    {
        if (a[i] < pivot)
        {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++, j++;
        }
        else if (pivot < a[i])
        {
            k--;
            int t = a[i];
            a[i] = a[k];
            a[k] = t;
        }
        else
            i++;
    }
    quick_sort(a, j);
    quick_sort(a + k, n - k);
    return;
}

bool is_sorted(int a[], int n)
{
    for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            return false;
    return true;
}
int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void generate(int *a, int *b, int *c, int n)
{
    for (int i = 0; i < n; i++)
        a[i] = b[i] = rand();
    qsort(b, n, sizeof(int), cmp);
    for (int i = 0; i < n; i++)
        c[i] = b[n - i - 1];
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
    for (int i = 1; i <= times; i++)
    {
        int l = rand() % n, r = rand() % n;
        while (l == r)
            l = rand() % n, r = rand() % n;
        int t = c[l];
        c[l] = c[r];
        c[r] = t;
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
    printf("%20s | %25s | time: %.6lf\n", type, name, time);
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
    int *a = (int *)malloc(sizeof(int) * n), *b = (int *)malloc(sizeof(int) * n), *c = (int *)malloc(sizeof(int) * n);
    generate(a, b, c, n);
    test(a, n, quick_sort, "Quick Sort", "Random Sequence");
    test(b, n, quick_sort, "Quick Sort", "Almost Ascending Sequence");
    test(c, n, quick_sort, "Quick Sort", "Almost Descending Sequence");
    test(a, n, quick_sort_stack, "Quick Sort Stack", "Random Sequence");
    test(b, n, quick_sort_stack, "Quick Sort Stack", "Almost Ascending Sequence");
    test(c, n, quick_sort_stack, "Quick Sort Stack", "Almost Descending Sequence");
    return 0;
}