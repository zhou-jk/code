#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int M = 500000, N = M << 1;
struct Edge
{
	int v, next;
	long long len;
} e[N + M];
long long s[N], x[M], y[M], d[N];
int head[N], q[N], tot, t;
bool vis[N];

inline void add_edge(int u, int v, long long len)
{
	e[++tot] = Edge{v, head[u], len};
	head[u] = tot;
}

inline int find(long long u)
{
	int l = 0, r = t;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (s[mid] > u)
			r = mid;
		else
			l = mid + 1;
	}
	return l - 1;
}

int main()
{
	freopen("tamnica.in", "r", stdin);
	freopen("tamnica.out", "w", stdout);
	int m, l, r;
	long long n, *b;
	scanf("%lld%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%lld%lld", &x[i], &y[i]);
		if (y[i] < x[i])
			swap(x[i], y[i]);
		s[i << 1] = x[i];
		s[(i << 1) | 1] = y[i];
	}
	s[m << 1] = 1;
	s[(m << 1) | 1] = n;
	t = (m + 1) << 1;
	sort(s, s + t);
	b = unique(s, s + t);
	t = b - s;
	for (int i = 0; i < m; i++)
		add_edge(find(x[i]), find(y[i]), 1);
	for (int i = 1; i < t; i++)
	{
		int len = s[i] - s[i - 1];
		add_edge(i - 1, i, len);
		add_edge(i, i - 1, len);
	}
	memset(d, 127, sizeof d);
	d[0] = 0;
	l = 0;
	r = 1;
	q[0] = 0;
	vis[0] = true;
	while (vis[q[l]])
	{
		vis[q[l]] = false;
		for (int i = head[q[l]]; i; i = e[i].next)
			if (d[q[l]] + e[i].len < d[e[i].v])
			{
				d[e[i].v] = d[q[l]] + e[i].len;
				if (!vis[e[i].v])
				{
					vis[e[i].v] = true;
					q[r] = e[i].v;
					r = (r + 1) % N;
				}
			}
		l = (l + 1) % N;
	}
	printf("%lld", d[find(n)]);
	return 0;
}