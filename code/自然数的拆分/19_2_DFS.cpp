// AC
#include <cstdio>

const int N = 1000000;
int s[N], n;

void dfs(int k, int num, int l)
{
	if (!num)
	{
		if (k == 1) return;
		printf("%d=", n);
		for (int i = 0; i < k; ++i)
		{
			if (i) putchar('+');
			printf("%d", s[i]);
		}
		putchar('\n');
		return;
	}
	for (int i = l; i <= num; ++i)
	{
		s[k] = i;
		dfs(k + 1, num - i, i);
	}
}

int main()
{
	scanf("%d", &n);
	dfs(0, n, 1);
	return 0;
}