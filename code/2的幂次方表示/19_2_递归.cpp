// AC
#include <cstdio>

void dfs(int n)
{
	int m;
	for (m = 0; 1 << m <= n; ++m)
		;
	bool flag = false;
	for (int i = m - 1; i > 1 && n; --i)
		if (n >= 1 << i)
		{
			if (flag) putchar('+');
			flag = true;
			printf("2(");
			dfs(i);
			putchar(')');
			n -= 1 << i;
		}
	if (n)
	{
		if (flag) putchar('+');
		switch (n)
		{
			case 3: printf("2+2(0)"); break;
			case 2: printf("2"); break;
			case 1: printf("2(0)"); break;
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	dfs(n);
	return 0;
}