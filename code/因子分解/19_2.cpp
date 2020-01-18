// AC
#include <cmath>
#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	int m = sqrt(n);
	bool flag = false;
	for (int i = 2; i <= m; ++i)
		if (!(n % i))
		{
			if (flag) putchar('*');
			flag = true;
			int cnt;
			for (cnt = 0; !(n % i); ++cnt) n /= i;
			printf("%d", i);
			if (cnt > 1) printf("^%d", cnt);
		}
	if (n > 1)
	{
		if (flag) putchar('*');
		printf("%d", n);
	}
	return 0;
}