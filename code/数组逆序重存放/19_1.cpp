// AC
#include <cstdio>

const int N = 100;
int a[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	for (int i = n - 1; ~i; --i) printf("%d ", a[i]);
	return 0;
}