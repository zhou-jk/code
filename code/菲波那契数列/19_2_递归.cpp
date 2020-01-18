// AC
#include <cstdio>

const int N = 20;
int f[N];

int dfs(int n)
{
	if (f[n]) return f[n];
	return f[n] = dfs(n - 1) + dfs(n - 2);
}

int main()
{
	int t;
	f[0] = f[1] = 1;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", dfs(n - 1));
	}
	return 0;
}