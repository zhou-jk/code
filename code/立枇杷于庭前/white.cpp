// AC
#include <bitset>
#include <cstdio>

using std::bitset;

const int N = 1000, M = 500000;
bitset<M + 1> f;

int main()
{
	freopen("white.in", "r", stdin);
	freopen("white.out", "w", stdout);
	int n, sum = 0, ans = 0;
	scanf("%d", &n);
	f[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		f ^= f << a;
		sum += a;
	}
	for (int i = 1; i <= sum; ++i) ans ^= f[i] * i;
	printf("%d", ans);
	return 0;
}