#include <cstdio>
#include <algorithm>

using std::sort;

const int N = 10000;
int a[N];

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("flower.in", "r", stdin);
	freopen("flower.out", "w", stdout);
	int n, m, ans = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n, cmp);
	for (int i = 0; i < m; i++)
		ans += a[i];
	printf("%d", ans);
	return 0;
}