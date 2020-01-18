// AC
#include <cstdio>
#include <cstring>

const int N = 20 + 1, LEN = 20;
char s[N][LEN + 1];
int len[N], vis[N], n, ans;

void dfs(int l, int last)
{
	if (l > ans) ans = l;
	for (int i = 0; i < n; ++i)
		if (vis[i] < 2)
		{
			++vis[i];
			for (int j = len[last] - 1; j > 0; --j)
				if (!strncmp(s[last] + j, s[i], len[last] - j))
				{
					dfs(l + len[i] - (len[last] - j), i);
					break;
				}
			--vis[i];
		}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s[i]);
		len[i] = strlen(s[i]);
	}
	s[n][0] = 'a';
	scanf("%s", s[n] + 1);
	len[n] = strlen(s[n]);
	dfs(1, n);
	printf("%d", ans);
	return 0;
}