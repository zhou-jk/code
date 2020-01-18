// AC
#include <cstdio>

const int N = 50000;
int fa[N * 3];

int getFa(int k)
{
	return k == fa[k] ? k : fa[k] = getFa(fa[k]);
}

void merge(int x, int y)
{
	fa[getFa(x)] = getFa(y);
}

int main()
{
	int n, m, ans = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n * 3; ++i) fa[i] = i;
	while (m--)
	{
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if (x > n || y > n)
		{
			++ans;
			continue;
		}
		--x;
		--y;
		if (op == 1)
		{
			if (getFa(x + n) == getFa(y) || getFa(y + n) == getFa(x))
				++ans;
			else
			{
				merge(x, y);
				merge(x + n, y + n);
				merge(x + (n << 1), y + (n << 1));
			}
		}
		else
		{
			if (getFa(x) == getFa(y) || getFa(y + n) == getFa(x))
				++ans;
			else
			{
				merge(x, y + (n << 1));
				merge(x + n, y);
				merge(x + (n << 1), y + n);
			}
		}
	}
	printf("%d", ans);
}