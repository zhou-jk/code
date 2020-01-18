// AC
#include <algorithm>
#include <cstdio>
#include <cstring>

using std::max;

const int N = 50000;
int a[N], b[N], n, st[16][N], bin[16], log[N];

int find1(int key)
{
	int l = 0, r = n - 1, mid;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (a[mid] <= key)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return r;
}

int find2(int key)
{
	int l = 0, r = n - 1, mid;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (a[mid] >= key)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return l;
}

int query(int l, int r)
{
	if (l > r) return -2000000000;
	int tmp = log[r - l + 1];
	return max(st[tmp][l], st[tmp][r - bin[tmp] + 1]);
}

void build(int n)
{
	bin[0] = 1;
	for (int i = 1; i <= 15; i++) bin[i] = bin[i - 1] << 1;
	log[1] = 0;
	for (int i = 2; i < n; i++) log[i] = log[i >> 1] + 1;
	memset(st, 128, sizeof st);
	for (int i = 0; i < n; i++) st[0][i] = b[i];
	for (int i = 1; i <= log[n - 1]; i++)
		for (int j = 0; j <= n - bin[i]; j++)
			st[i][j] = max(st[i - 1][j], st[i - 1][j + bin[i - 1]]);
}

int main()
{
	int m, c, d;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", a + i, b + i);
	build(n);
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d%d", &c, &d);
		if (d <= c)
		{
			puts("false");
			continue;
		}
		int l = find2(c), r = find1(d);
		if (r < 0 || l >= n || (c < a[l] && a[r] < d))
			puts("maybe");
		else
		{
			if (a[l] == c && a[r] == d)
			{
				if (b[r] > b[l] || query(l + 1, r - 1) >= b[r])
					puts("false");
				else if (r - l == d - c)
					puts("true");
				else
					puts("maybe");
			}
			else if (a[l] == c)
			{
				if (query(l + 1, r) >= b[l])
					puts("false");
				else
					puts("maybe");
			}
			else if (a[r] == d)
			{
				if (query(l, r - 1) >= b[r])
					puts("false");
				else
					puts("maybe");
			}
		}
	}
	return 0;
}