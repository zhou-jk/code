// AC
#include <cstdio>

const int N = 1000 << 1;
int fa[N], cnt[N];
bool vis[N];

int getFa(const int k)
{
	return k == fa[k] ? k : fa[k] = getFa(fa[k]);
}

void merge(const int x, const int y)
{
	int faX = getFa(x), faY = getFa(y);
	if (faX == faY) return;
	if (cnt[faX] < cnt[faY])
	{
		fa[faX] = faY;
		cnt[faY] += cnt[faX];
	}
	else
	{
		fa[faY] = faX;
		cnt[faX] += cnt[faY];
	}
}

int main()
{
	int n, m, ans = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < (n << 1); ++i)
	{
		fa[i] = i;
		cnt[i] = 1;
	}
	while (m--)
	{
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		--x;
		--y;
		if (op)
		{
			merge(x + n, y);
			merge(x, y + n);
		}
		else
			merge(x, y);
	}
	for (int i = 0; i < n; ++i)
	{
		int tmp = getFa(i);
		if (!vis[tmp])
		{
			vis[tmp] = true;
			++ans;
		}
	}
	printf("%d", ans);
	return 0;
}