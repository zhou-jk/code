// AC
#include <cstdio>

const int N = 1000;
int fa[N << 1], cnt[N << 1];
bool vis[N << 1];

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
	char nu[4];
	int n, m, ans = 0;
	scanf("%d%d", &n, &m);
	gets(nu);
	for (int i = 0; i < (n << 1); ++i)
	{
		fa[i] = i;
		cnt[i] = 1;
	}
	while (m--)
	{
		char op;
		int x, y;
		scanf("%c %d%d", &op, &x, &y);
		--x;
		--y;
		gets(nu);
		// printf("%d#%c %d %d\n", m, op, x, y);
		if (op == 'F')
			merge(x, y);
		else
		{
			merge(x + n, y);
			merge(x, y + n);
		}
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