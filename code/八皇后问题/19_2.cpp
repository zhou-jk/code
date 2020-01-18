// AC
#include <cstdio>

const int N = 8;
int ans[N], cnt;
bool vis1[N], vis2[(N << 1) - 1], vis3[(N << 1) - 1];

void dfs(int k)
{
	if (k == N)
	{
		printf("No. %d\n", ++cnt);
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j) printf("%d ", i == ans[j]);
			putchar('\n');
		}
		return;
	}
	for (int i = 0; i < N; ++i)
		if (!vis1[i] && !vis2[k - i + N - 1] && !vis3[k + i])
		{
			vis1[i] = vis2[k - i + N - 1] = vis3[k + i] = true;
			ans[k] = i;
			dfs(k + 1);
			vis1[i] = vis2[k - i + N - 1] = vis3[k + i] = false;
		}
}

int main()
{
	dfs(0);
	return 0;
}