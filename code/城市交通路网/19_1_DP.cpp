// AC
#include <algorithm>
#include <cstdio>
#include <cstring>

using std::min;

const int N = 1000;
int a[N][N], f[N], g[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) scanf("%d", &a[i][j]);
	memset(f, 63, sizeof f);
	f[n - 1] = 0;
	for (int i = n - 2; ~i; --i)
		for (int j = i + 1; j < n; ++j)
			if (a[i][j] && f[j] + a[i][j] < f[i])
				f[i] = f[j] + a[i][j], g[i] = j;
	printf("minlong=%d\n", f[0]);
	int k = 0;
	do
	{
		printf("%d ", k + 1);
		k = g[k];
	} while (k);
	return 0;
}