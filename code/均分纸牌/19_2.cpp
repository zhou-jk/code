// AC
#include <cstdio>

const int N = 100;
int a[N];

int main()
{
	int n, sum = 0, avg, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
		sum += a[i];
	}
	avg = sum / n;
	for (int i = 0; i < n; ++i)
		if (a[i] != avg)
		{
			a[i + 1] += a[i] - avg;
			++ans;
		}
	printf("%d", ans);
	return 0;
}