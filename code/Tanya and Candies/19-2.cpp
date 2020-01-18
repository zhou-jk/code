#include <cstdio>

const int N = 200000;
int a[N + 1], sum[N + 1][2];

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", a + i);
		sum[i][0] = sum[i - 1][0];
		sum[i][1] = sum[i - 1][1];
		sum[i][i & 1] += a[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		ans += sum[i - 1][0] + sum[n][1] - sum[i][1]
			   == sum[i - 1][1] + sum[n][0] - sum[i][0];
		/*if (sum[i - 1][0] + sum[n][1] - sum[i][1]
			== sum[i - 1][1] + sum[n][0] - sum[i][0])
			printf("%d\n", i);*/
	}
	printf("%d", ans);
	return 0;
}