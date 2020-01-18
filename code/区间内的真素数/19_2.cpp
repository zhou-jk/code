// AC
#include <cmath>
#include <cstdio>

int change(int n)
{
	int ret = 0;
	while (n)
	{
		ret = ret * 10 + n % 10;
		n /= 10;
	}
	return ret;
}

bool check(int n)
{
	if (n < 2) return false;
	int m = sqrt(n);
	for (int i = 2; i <= m; ++i)
		if (!(n % i)) return false;
	return true;
}

int main()
{
	int l, r;
	bool flag = false;
	scanf("%d%d", &l, &r);
	for (int i = l; i < r; ++i)
		if (check(i) && check(change(i)))
		{
			if (flag) putchar(',');
			flag = true;
			printf("%d", i);
		}
	if (!flag) puts("No");
	return 0;
}