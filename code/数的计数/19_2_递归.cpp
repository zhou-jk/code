// AC
#include <cstdio>

const int N = 1000;
int f[N + 1];

void dfs(int n)
{
	if (f[n]) return;
	int m = n >> 1;
	f[n] = 1;
	for (int i = 1; i <= m; ++i)
	{
		dfs(i);
		f[n] += f[i];
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	dfs(n);
	printf("%d", f[n]);
	return 0;
}