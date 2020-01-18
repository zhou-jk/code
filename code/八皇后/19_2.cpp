// AC
#include <cstdio>

const int N = 8, N_ANS = 92;
int s[N], ans[N_ANS], cnt;
bool vis1[N], vis2[(N << 1) - 1], vis3[(N << 1) - 1];

void dfs(int k)
{
	if (k == N)
	{
		for (int i = 0; i < N; ++i) ans[cnt] = ans[cnt] * 10 + s[i] + 1;
		++cnt;
	}
	for (int i = 0; i < N; ++i)
		if (!vis1[i] && !vis2[k - i + N - 1] && !vis3[k + i])
		{
			vis1[i] = vis2[k - i + N - 1] = vis3[k + i] = true;
			s[k] = i;
			dfs(k + 1);
			vis1[i] = vis2[k - i + N - 1] = vis3[k + i] = false;
		}
}

int main()
{
	int t;
	dfs(0);
	scanf("%d", &t);
	while (t--)
	{
		int k;
		scanf("%d", &k);
		printf("%d\n", ans[k - 1]);
	}
	return 0;
}