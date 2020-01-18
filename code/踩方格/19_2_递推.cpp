// AC
#include <cstdio>

const int N = 20;
int f[N][3];

int main()
{
	int n;
	scanf("%d", &n);
	f[0][0] = f[0][1] = f[0][2] = 1;
	for (int i = 1; i < n; ++i)
	{
		f[i][0] = f[i - 1][1] + f[i - 1][2];
		f[i][1] = f[i - 1][0] + f[i - 1][2];
		f[i][2] = f[i - 1][0] + f[i - 1][1] + f[i - 1][2];
	}
	printf("%d", f[n - 1][0] + f[n - 1][1] + f[n - 1][2]);
	return 0;
}