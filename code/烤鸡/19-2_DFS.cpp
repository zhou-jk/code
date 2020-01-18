// AC
#include <cstdio>

const int M = 10, N_ANS = 10000;
int tmp[M], ans[N_ANS][M], cnt;

void dfs(int k, int n)
{
	if (n > (M - k) * 3 || n < M - k) return;
	if (k == M)
	{
		for (int i = 0; i < M; ++i) ans[cnt][i] = tmp[i];
		++cnt;
		return;
	}
	for (int i = 1; i <= 3; ++i)
	{
		tmp[k] = i;
		dfs(k + 1, n - i);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	dfs(0, n);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < M; ++j) printf("%d ", ans[i][j]);
		putchar('\n');
	}
	return 0;
}