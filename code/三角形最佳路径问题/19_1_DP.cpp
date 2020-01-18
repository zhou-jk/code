// AC
#include <algorithm>
#include <cstdio>

using std::max;

const int N = 100;
int a[N][N], f[N][N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= i; ++j) scanf("%d", &a[i][j]);
	for (int i = 0; i < n; ++i) f[n - 1][i] = a[n - 1][i];
	for (int i = n - 2; ~i; --i)
		for (int j = 0; j <= i; ++j)
			f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + a[i][j];
	printf("%d", f[0][0]);
	return 0;
}