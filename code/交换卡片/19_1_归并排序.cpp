// AC
#include <cstdio>

const int N = 500000;
int a[N], b[N];
long long ans;

void mergesort(int l, int r)
{
	if (l >= r) return;
	int mid = (l + r) >> 1;
	int i = l, j = mid + 1, k = l;
	mergesort(l, mid);
	mergesort(mid + 1, r);
	while (i <= mid && j <= r)
		if (a[i] <= a[j])
			b[k++] = a[i++];
		else
			ans += mid - i + 1, b[k++] = a[j++];
	for (; i <= mid; ++i) b[k++] = a[i];
	for (; j <= r; ++j) b[k++] = a[j];
	for (int i = l; i <= r; ++i) a[i] = b[i];
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	mergesort(0, n - 1);
	printf("%lld", ans);
	return 0;
}