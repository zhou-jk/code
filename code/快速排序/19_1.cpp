// AC
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using std::swap;

const int N = 100000;
int a[N];

void qsort(int l, int r)
{
	if (l >= r) return;
	int i = l, j = r, tmp = a[l + rand() % (r - l + 1)];
	// printf("%d %d %d\n", l, r, tmp);
	// for (int i = l; i <= r; ++i) printf("%d ", a[i]);
	// puts("");
	while (i <= j)
	{
		while (a[i] < tmp) ++i;
		while (a[j] > tmp) --j;
		if (i <= j) swap(a[j--], a[i++]);
	}
	// for (int i = l; i <= r; ++i) printf("%d ", a[i]);
	// printf("\n%d %d\n", j, i);
	qsort(l, j);
	qsort(i, r);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	srand(time(NULL));
	qsort(0, n - 1);
	for (int i = 0; i < n - 1; ++i) printf("%d ", a[i]);
	printf("%d\n", a[n - 1]);
	return 0;
}