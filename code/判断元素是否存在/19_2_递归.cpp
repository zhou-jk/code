// AC
#include <cstdio>
#include <cstdlib>

int b;

void dfs(int a)
{
	if (a > b) return;
	if (a == b)
	{
		puts("YES");
		exit(0);
	}
	dfs(2 * a + 1);
	dfs(3 * a + 1);
}

int main()
{
	int a;
	scanf("%d,%d", &a, &b);
	dfs(a);
	puts("NO");
	return 0;
}