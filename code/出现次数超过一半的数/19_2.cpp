// AC
#include <cstdio>

const int N = 1000, MIN = -50, MAX = 50;
int cnt[MAX - MIN + 1];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		++cnt[tmp - MIN];
	}
	for (int i = 0; i < MAX - MIN; ++i)
		if (cnt[i] > (n >> 1))
		{
			printf("%d", i + MIN);
			return 0;
		}
	puts("no");
	return 0;
}