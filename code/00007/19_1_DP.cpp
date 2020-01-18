// AC
#include <algorithm>
#include <cstdio>

using std::max;

const int M = 200;
int f[M + 1];

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; ++i)
	{
		int w, c;
		scanf("%d%d", &w, &c);
		for (int j = m; j >= w; --j) f[j] = max(f[j], f[j - w] + c);
	}
	printf("%d", f[m]);
	return 0;
}