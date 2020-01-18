// AC
#include <cstdio>

char solve(int num)
{
	if (num > 9) return num - 10 + 'A';
	return num + '0';
}

void dfs(int a, int b)
{
	if (!a) return;
	dfs(a / b, b);
	putchar(solve(a % b));
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	dfs(a, b);
	return 0;
}