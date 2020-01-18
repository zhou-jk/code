// VOJ HDU 1711
#include <cstdio>

template <typename T>
void make_next(const T arr[], const int len, int next[])
{
    next[0] = 0;
    for (int i = 1, k = 0; i < len; i++)
    {
	while (k && arr[i] != arr[k]) k = next[k - 1];
	if (arr[i] == arr[k]) k++;
	next[i] = k;
    }
}

template <typename T>
int pos(const T a[], const int len_a, const T b[],
	const int len_b)
{
    int *next = new int[len_b];
    make_next<T>(b, len_b, next);
    for (int i = 0, k = 0; i < len_a; i++)
    {
	while (k && a[i] != b[k]) k = next[k - 1];
	if (a[i] == b[k]) k++;
	if (k == len_b)
	{
	    delete[] next;
	    return i - k + 1;
	}
    }
    delete[] next;
    return -1;
}

int main()
{
    int n, m, t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
	scanf("%d%d", &n, &m);
	int *a = new int[n], *b = new int[m];
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]);
	int tmp;
	printf("%d\n", (tmp = pos<int>(a, n, b, m)) < 0 ?
			   tmp :
			   tmp + 1);
	delete[] a;
	delete[] b;
    }
    return 0;
}