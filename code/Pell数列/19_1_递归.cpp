// AC
#include <cstdio>

const int N = 1000000, P = 32767;
int f[N];

int dfs(int n)
{
	if (f[n]) return f[n];
	return f[n] = (dfs(n - 1) * 2 + dfs(n - 2)) % P;
}

int main()
{
	int t;
	f[0] = 1;
	f[1] = 2;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", dfs(n - 1));
	}
	return 0;
}