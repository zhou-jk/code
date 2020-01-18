// AC
// AC
#include <cmath>
#include <cstdio>

bool check(int num)
{
	int m = sqrt(num);
	for (int i = 2; i <= m; ++i)
		if (!(num % i)) return false;
	return true;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i)
		if (check(i) && check(i + 2)) printf("%d %d\n", i, i + 2);
	return 0;
}