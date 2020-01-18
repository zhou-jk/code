// AC
#include <cstdio>
#include <cstring>

const int N = 200;
int a[N], f[N], g[N];

void solve(int k)
{
	if (k < 0) return;
	solve(g[k]);
	printf("%d ", a[k]);
}

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	memset(g, -1, sizeof g);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
		for (int j = 0; j < i; ++j)
			if (a[j] <= a[i] && f[j] > f[i]) f[i] = f[j], g[i] = j;
		++f[i];
		if (f[i] > f[ans]) ans = i;
	}
	printf("max=%d\n", f[ans]);
	solve(ans);
	return 0;
}