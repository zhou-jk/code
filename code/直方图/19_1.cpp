// AC
#include <cstdio>

const int MAX = 10000;
int f[MAX + 1];

int main()
{
	int n, max = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		max = a > max ? a : max;
		++f[a];
	}
	for (int i = 0; i <= max; ++i) printf("%d\n", f[i]);
	return 0;
}