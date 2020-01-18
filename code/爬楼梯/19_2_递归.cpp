// AC
#include <cstdio>

const int N = 30;
int f[N + 1];

int dfs(int n)
{
	if (f[n]) return f[n];
	return f[n] = dfs(n - 1) + dfs(n - 2);
}

int main()
{
	int n;
	f[0] = f[1] = 1;
	while (scanf("%d", &n) != EOF) printf("%d\n", dfs(n));
	return 0;
}