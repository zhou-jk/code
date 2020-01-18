// AC
#include <cstdio>

const int N = 20;
int f[N + 1];

int main()
{
	int n;
	scanf("%d", &n);
	f[0] = f[1] = 1;
	for (int i = 2; i <= n; ++i) f[i] = f[i - 1] + f[i - 2];
	printf("%d", f[n]);
	return 0;
}