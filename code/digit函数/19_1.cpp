// AC
#include <cstdio>

int digit(int n, int k)
{
	if (k == 1) return n % 10;
	return digit(n / 10, k - 1);
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	printf("%d", digit(n, k));
	return 0;
}