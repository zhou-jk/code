// AC
#include <algorithm>
#include <cstdio>

using std::min;

const int N = 100;
int a[N][N], f[N][N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) scanf("%d", &a[i][j]);
	f[0][0] = a[0][0];
	for (int i = 1; i < n; ++i)
	{
		f[i][0] = f[i - 1][0] + a[i][0];
		f[0][i] = f[0][i - 1] + a[0][i];
	}
	for (int i = 1; i < n; ++i)
		for (int j = 1; j < n; ++j)
			f[i][j] = min(f[i - 1][j], f[i][j - 1]) + a[i][j];
	printf("%d", f[n - 1][n - 1]);
	return 0;
}