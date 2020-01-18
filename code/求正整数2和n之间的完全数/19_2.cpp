// AC
#include <cmath>
#include <cstdio>

bool check(int num)
{
	int m = sqrt(num);
	int tmp = 1;
	for (int i = 2; i <= m; ++i)
		if (!(num % i)) tmp += i + num / i;
	if (m * m == num) tmp -= m;
	return num == tmp;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i)
		if (check(i)) printf("%d\n", i);
	return 0;
}