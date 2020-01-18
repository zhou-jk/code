#include <cstdio>

int s[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int solve(int n)
{
	int ret = 0;
	do
	{
		ret += s[n % 10];
		n /= 10;
	} while (n);
	return ret;
}

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i <= 1111; ++i)
		for (int j = 0; j <= 1111; ++j)
			ans += solve(i) + solve(j) + solve(i + j) == n - 4;
	printf("%d", ans);
	return 0;
}