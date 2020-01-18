#include <algorithm>
#include <cmath>
#include <cstdio>

const double EPS = 1e-4;

using std::min;
using std::printf;
using std::scanf;
using std::swap;

double dis(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
	freopen("closer.in", "r", stdin);
	freopen("closer.out", "w", stdout);
	int xA, yA, xB, yB, xC, yC, xD, yD, v1, v2, v3;
	double ans = 1E11;
	scanf("%d%d%d%d%d%d%d%d%d%d%d", &xA, &yA, &xB, &yB, &xC, &yC, &xD, &yD, &v1,
		  &v2, &v3);

	printf("%.2f", ans);
	return 0;
}