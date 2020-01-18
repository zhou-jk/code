// AC
#include <algorithm>
#include <cstdio>

using std::sort;
using std::swap;

const int N = 100000;
int a[N];

int main()
{
	freopen("diff.in", "r", stdin);
	freopen("diff.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	sort(a, a + n);
	swap(a[0], a[n - 1]);
	for (int i = 0; i < n; ++i) printf("%d ", a[i]);
	return 0;
}
