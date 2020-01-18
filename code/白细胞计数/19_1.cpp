// AC
#include <algorithm>
#include <cmath>
#include <cstdio>

using std::max;
using std::sort;

const int N = 300;
double a[N];

int main()
{
	int n;
	double ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%lf", a + i);
	sort(a, a + n);
	for (int i = 1; i < n - 1; ++i) ans += a[i];
	ans /= n - 2;
	printf("%.2lf %.2lf", ans, max(fabs(ans - a[1]), fabs(ans - a[n - 2])));
	return 0;
}