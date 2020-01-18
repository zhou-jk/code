#include <cstdio>

const int N = 100000;
int s[2][N << 1];

int main()
{
	freopen("alb.in", "r", stdin);
	freopen("alb.out", "w", stdout);
	int n, k, sum = 0, ans = 0;
	scanf("%d%d", &n, &k);
	s[1][N] = 1;
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		sum += a < k ? -1 : !(a == k);
		ans += s[!(i & 1)][sum + N];
		// printf("%d %d\n", i, s[!(i & 1)][sum + N]);
		++s[i & 1][sum + N];
	}
	printf("%d", ans);
	return 0;
}