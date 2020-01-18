// AC
#include <cstdio>
#include <cstring>

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n;
	scanf("%d", &n);
	if (n < 2) printf("%d", n);
	if (n == 2) puts("4");
	if (n > 3) puts("-1");
	return 0;
}