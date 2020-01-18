#include <algorithm>
#include <cstdio>

using std::max;

const int N = 1000000;
int v[N], l[N], r[N], s[N], cnt, ans;
bool flag;

void dfs(int k)
{
	if (k < 0) return;
	int bak1 = cnt;
	dfs(l[k]);
	int bak2 = cnt;
	s[cnt++] = v[k];
	dfs(r[k]);
	if (cnt - (bak2 + 1) != bak2 - bak1) return;
	flag = true;
	for (int i = bak1; i < bak2; ++i)
		if (s[i] != s[cnt - 1 - (i - bak1)])
		{
			flag = false;
			break;
		}

	if (flag) ans = max(ans, cnt - bak1);
}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &l[i], &r[i]);
		--l[i];
		--r[i];
	}
	dfs(0);
	printf("%d", ans);
	return 0;
}