// AC
#include <algorithm>
#include <cstdio>

using std::max;

int main()
{
	int n, x, y, tx, ty;
	scanf("%d%d%d", &n, &x, &y);
	for (int i = 1; i <= n; ++i) printf("(%d,%d) ", x, i);
	putchar('\n');
	for (int i = 1; i <= n; ++i) printf("(%d,%d) ", i, y);
	putchar('\n');
	tx = max(x - y, 0);
	ty = max(y - x, 0);
	for (int i = 1; tx + i <= n && ty + i <= n; ++i)
		printf("(%d,%d) ", tx + i, ty + i);
	putchar('\n');
	tx = x + y;
	for (int i = 1; i <= n && tx - i > 0; ++i)
		if (tx - i <= n) printf("(%d,%d) ", tx - i, i);
	return 0;
}