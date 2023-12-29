#include <stdlib.h>
#include <stdbool.h>

void bubble_sort(int a[], int n)
{
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                flag = true;
                int t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;
            }
        }
    }
    return;
}

void selection_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int ith = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[ith])
                ith = j;
        int t = a[i];
        a[i] = a[ith];
        a[ith] = t;
    }
    return;
}

void insertion_sort(int a[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    return;
}

void merge_sort_runner(int a[], int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    merge_sort_runner(a, l, mid);
    merge_sort_runner(a, mid + 1, r);
    int k = 0;
    int *b = (int *)malloc(sizeof(int) * (r - l + 1));
    int i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
            b[k] = a[i], i++;
        else
            b[k] = a[j], j++;
        k++;
    }
    while (i <= mid)
        b[k] = a[i], i++, k++;
    while (j <= r)
        b[k] = a[j], j++, k++;
    for (int i = l; i <= r; i++)
        a[i] = b[i - l];
    free(b);
    return;
}
void merge_sort(int a[], int n)
{
    return merge_sort_runner(a, 0, n - 1);
}

void quick_sort_runner(int a[], int l, int r)
{
    if (l >= r)
        return;
    int x = a[r];
    int mid = l - 1;
    for (int i = l; i < r; i++)
        if (a[i] <= x)
        {
            mid++;
            int t = a[mid];
            a[mid] = a[i], a[i] = t;
        }
    mid++;
    int t = a[mid];
    a[mid] = a[r], a[r] = t;
    quick_sort_runner(a, l, mid - 1);
    quick_sort_runner(a, mid + 1, r);
    return;
}

void quick_sort(int a[], int n)
{
    return quick_sort_runner(a, 0, n - 1);
}

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
void stdlib_sort(int a[], int n)
{
    qsort(a, n, sizeof(int), cmp);
    return;
}

void radix_sort(int a[], int n)
{
    int *b = (int *)malloc(sizeof(int) * n);
    int cnt[1 << 8];
    int mask = (1 << 8) - 1;
    int *x = a, *y = b;
    for (int i = 0; i < 32; i += 8)
    {
        for (int j = 0; j != (1 << 8); j++)
            cnt[j] = 0;
        for (int j = 0; j != n; j++)
            ++cnt[x[j] >> i & mask];
        for (int sum = 0, j = 0; j != (1 << 8); j++)
            sum += cnt[j], cnt[j] = sum - cnt[j];
        for (int j = 0; j != n; j++)
            y[cnt[x[j] >> i & mask]++] = x[j];
        int *t = x;
        x = y, y = t;
    }
    free(b);
    return;
}