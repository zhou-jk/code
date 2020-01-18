#include <cstdio>

const int N = 31;
int f[N];

char solve(int s, int k)
{
	if (k <= f[s - 1]) return solve(s - 1, k);
	int tmp = k - f[s - 1];
	if (tmp <= s + 3) return tmp == 1 ? 'm' : 'o';
	return solve(s - 1, tmp - (s + 3));
}

int main()
{
	int n;
	scanf("%d", &n);
	f[0] = 3;
	int i;
	for (i = 1; f[i - 1] < n; ++i) f[i] = i + 3 + (f[i - 1] << 1);
	putchar(solve(i - 1, n));
	return 0;
}