// AC
#include <algorithm>
#include <cstdio>

using std::printf;
using std::scanf;
using std::sort;

const int N = 1000;
int a[N], r[N];

bool cmp(int x, int y)
{
	return a[x] < a[y];
}

int main()
{
	int n;
	long long sum = 0, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
		r[i] = i;
	}
	sort(r, r + n, cmp);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", r[i] + 1);
		ans += sum;
		sum += a[r[i]];
	}
	printf("\n%.2f", (double)ans / n);
	return 0;
}