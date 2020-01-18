// AC
#include <algorithm>
#include <cstdio>
#include <cstring>

using std::max;

const int N = 100;
int a[N][N], sum[N];

int main()
{
	int n, ans = -1E9;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) scanf("%d", &a[i][j]);
	for (int i = 0; i < n; ++i)
	{
		memset(sum, 0, sizeof sum);
		for (int j = i; j < n; ++j)
		{
			int sum1 = 0;
			for (int k = 0; k < n; ++k)
			{
				sum[k] += a[k][j];
				sum1 += sum[k];
				ans = max(ans, sum1);
				sum1 = max(sum1, 0);
			}
		}
	}
	printf("%d", ans);
	return 0;
}