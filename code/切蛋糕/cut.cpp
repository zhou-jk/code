// AC
#include <algorithm>
#include <cstdio>

using std::max;
using std::min;
using std::sort;

const int N = 1000;
struct Node
{
	int x, y;
} node[N + 1];
int x[N + 1], a[N], b[N], n;

bool cmp(const Node &a, const Node &b)
{
	return a.y < b.y;
}

int main()
{
	freopen("cut.in", "r", stdin);
	freopen("cut.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &node[i].x, &node[i].y);
		x[i] = node[i].x;
	}
	sort(x, x + n);
	sort(node, node + n, cmp);
	x[n] = node[n].y = -1;
	int ans = n;
	for (int i = 0; i < n; ++i)
		if (x[i] != x[i + 1])
		{
			int c = 0, d = 0;
			a[0] = b[0] = 0;
			if (node[0].x > x[i])
				b[0] = 1;
			else
				a[0] = 1;
			for (int j = 1; j < n; ++j)
			{
				a[j] = a[j - 1];
				b[j] = b[j - 1];
				if (node[j].x > x[i])
					++b[j];
				else
					++a[j];
			}
			ans = min(ans, max(a[n - 1], b[n - 1]));
			for (int j = n - 1; j; --j)
			{
				if (node[j].x > x[i])
					++d;
				else
					++c;
				if (node[j].y != node[j - 1].y)
					ans = min(ans, max(max(a[j - 1], b[j - 1]), max(c, d)));
			}
		}
	printf("%d", ans);
	return 0;
}