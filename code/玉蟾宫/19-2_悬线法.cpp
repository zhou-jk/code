#include <algorithm>
#include <cstdio>
#include <functional>
#include <utility>

using std::less;
using std::make_pair;
using std::max;
using std::min;
using std::pair;

const int N = 1000;
int f[N][N];

int main()
{
	int n, m, ans = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{

			f[i][j] = j && a[i][j] ? f[i][j - 1] + 1 : a[i][j];
			ans1 = max(ans1, g[i][j] * g[i][j]);
		}
	printf("%d", ans);
	return 0;
}