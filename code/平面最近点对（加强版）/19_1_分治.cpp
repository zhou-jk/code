// AC
#include <algorithm>
#include <cmath>
#include <cstdio>

using std::min;
using std::sort;

const int N = 200000;
struct Node
{
	double x, y;
} node[N], c[N];
int b[N];

bool cmp(Node &a, Node &b)
{
	return a.x < b.x;
}

double dist(Node &a, Node &b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double solve(int l, int r)
{
	if (l >= r) return 1e12;
	int mid = (l + r) >> 1;
	double midx = node[mid].x;
	double ans = min(solve(l, mid), solve(mid + 1, r));
	int t = 0;
	for (int i = mid + 1; i <= r; ++i)
		if (node[i].x - midx < ans) b[t++] = i;
	for (int i = l, j = 0; i <= mid; ++i)
	{
		while (j < t && node[i].y - node[b[j]].y >= ans) ++j;
		for (int k = j; k < t && k < j + 6; ++k)
			ans = min(ans, dist(node[i], node[b[k]]));
	}
	int i = t = l, j = mid + 1;
	while (i <= mid && j <= r)
		c[t++] = node[i].y < node[j].y ? node[i++] : node[j++];
	while (i <= mid) c[t++] = node[i++];
	while (j <= r) c[t++] = node[j++];
	for (int i = l; i <= r; ++i) node[i] = c[i];
	return ans;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%lf%lf", &node[i].x, &node[i].y);
	sort(node, node + n, cmp);
	printf("%.4lf", solve(0, n - 1));
	return 0;
}