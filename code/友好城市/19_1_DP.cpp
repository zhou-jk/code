// AC
#include <algorithm>
#include <cstdio>

using std::max;
using std::sort;

const int N = 5000;
struct Node
{
	int a, b;
} node[N];
int f[N];

bool cmp(Node &a, Node &b)
{
	return a.a < b.a;
}

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d%d", &node[i].a, &node[i].b);
	sort(node, node + n, cmp);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
			if (node[i].b > node[j].b) f[i] = max(f[i], f[j]);
		++f[i];
		ans = max(ans, f[i]);
	}
	printf("%d", ans);
	return 0;
}