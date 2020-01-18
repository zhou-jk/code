#include <cstdio>

void dfs(int n, char a, char b, char c)
{
	if (!n) return;
	dfs(n - 1, a, c, b);
	printf("%c->%d->%c\n", a, n, c);
	dfs(n - 1, b, a, c);
}

int main()
{
	int n;
	char a, b, c;
	scanf("%d %c %c %c", &n, &a, &b, &c);
	dfs(n, a, c, b);
	return 0;
}