// AC
#include <algorithm>
#include <cstdio>
#include <functional>

using std::greater;
using std::sort;

const int N = 10;
int a[2][N + 1];

int main()
{
	for (int i = 0; i < N; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		a[tmp & 1][++a[tmp & 1][0]] = tmp;
	}
	sort(a[0] + 1, a[0] + 1 + a[0][0]);
	sort(a[1] + 1, a[1] + 1 + a[1][0], greater<int>());
	for (int i = 1; i <= a[1][0]; ++i) printf("%d ", a[1][i]);
	for (int i = 1; i <= a[0][0]; ++i) printf("%d ", a[0][i]);
	return 0;
}