// AC
#include <algorithm>
#include <cstdio>

using std::max;

const int M = 6000;
int f[M];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		int v, w, s;
		scanf("%d%d%d", &v, &w, &s);
		for (int j = m; ~j; --j)
			for (int k = 0; k <= s && k <= j / v; ++k)
				f[j] = max(f[j], f[j - k * v] + k * w);
	}
	printf("%d", f[m]);
	return 0;
}