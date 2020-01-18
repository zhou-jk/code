// AC
#include <cstdio>

typedef unsigned long long ULL;

const int N = 10;
int a[N], n, ans = N;
ULL s[N];

ULL gcd(ULL a, ULL b)
{
	return b ? gcd(b, a % b) : a;
}

void dfs(int k, int cnt)
{
	if (k == n)
	{
		if (cnt < ans) ans = cnt;
		return;
	}
	for (int i = 0; i < cnt; ++i)
		if (gcd(s[i], a[k]) == 1)
		{
			s[i] *= a[k];
			dfs(k + 1, cnt);
			s[i] /= a[k];
		}
	s[cnt] = a[k];
	dfs(k + 1, cnt + 1);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	dfs(0, 0);
	printf("%d", ans);
	return 0;
}