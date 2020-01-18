// AC
#include <algorithm>
#include <cstdio>

using std::sort;
using std::unique;

const int N = 100;
int a[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	sort(a, a + n);
	n = unique(a, a + n) - a;
	printf("%d\n", n);
	for (int i = 0; i < n; ++i) printf("%d ", a[i]);
	return 0;
}