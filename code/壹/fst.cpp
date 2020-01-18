// AC
#include <cctype>
#include <cstdio>
#include <cstring>

const int N = 1000000;
struct Edge
{
	int v, dis, next;
} edge[N - 1];
int head[N], n, cnt;
long long ans;

inline char get_char()
{
	static const int SIZE = 2 << 16;
	static char buf[SIZE], *s, *t;
	if (s == t)
	{
		t = (s = buf) + fread(buf, 1, SIZE, stdin);
		if (s == t) return EOF;
	}
	return *s++;
}

#define getchar get_char

inline int get_int()
{
	char c;
	int ret = 0;
	for (c = getchar(); !isdigit(c); c = getchar())
		;
	for (; isdigit(c); c = getchar()) ret = (ret << 1) + (ret << 3) + (c ^ 48);
	return ret;
}

void AddEdge(const int u, const int v, const int dis)
{
	edge[cnt].v = v;
	edge[cnt].dis = dis;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

int dfs(int k)
{
	int ret = 1;
	for (int i = head[k]; ~i; i = edge[i].next)
	{
		int size = dfs(edge[i].v);
		ans += (long long)size * (n - size) * edge[i].dis;
		ret += size;
	}
	return ret;
}

int main()
{
	freopen("fst.in", "r", stdin);
	freopen("fst.out", "w", stdout);
	n = get_int();
	memset(head, -1, sizeof head);
	for (int i = 1; i < n; ++i)
	{
		int fa = get_int() - 1, dis = get_int();
		AddEdge(fa, i, dis);
	}
	dfs(0);
	printf("%lld", ans * 2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
