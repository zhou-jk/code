// AC
#include <cstdio>
#include <cstring>

const int LEN = 6;
char s[LEN + 1], ans[LEN + 1];
bool vis[LEN];
int len;

void dfs(int k)
{
	if (k == len)
	{
		puts(ans);
		return;
	}
	for (int i = 0; i < len; ++i)
		if (!vis[i])
		{
			vis[i] = true;
			ans[k] = s[i];
			dfs(k + 1);
			vis[i] = false;
		}
}

int main()
{
	scanf("%s", s);
	len = strlen(s);
	dfs(0);
	return 0;
}