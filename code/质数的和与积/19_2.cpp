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
	int n, ans = 0;
	scanf("%d", &n);
	int m = n >> 1;
	for (int i = 2; i <= m; ++i)
		if (check(i) && check(n - i)) ans = i * (n - i);
	printf("%d", ans);
	return 0;
}