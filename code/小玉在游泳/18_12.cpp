// AC
#include <cstdio>

int main()
{
	double tar, s = 2, tmp = 0;
	scanf("%lf", &tar);
	int ans;
	for (ans = 0; tmp < tar; ++ans) tmp += s, s *= 0.98;
	printf("%d", ans);
	return 0;
}