// AC
#include <cstdio>

const int N = 1000, P = 12345;
int f[N + 1][2];

int main()
{
	int n;
	scanf("%d", &n);
	f[0][0] = 1;
	f[0][1] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < i; ++j)
		{
			f[i][0] = (f[i][0] + f[j][1] + f[j][0] * 8) % P;
			f[i][1] = (f[i][1] + f[j][0] + f[j][1] * 8) % P;
		}
	printf("%d", f[n][0]);
	return 0;
}