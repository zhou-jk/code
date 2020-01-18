// AC
#include <cstdio>

int main()
{
	int n, sum = 0;
	scanf("%d", &n);
	for (int i = 1;; ++i)
	{
		sum += i;
		if (sum > n && !((sum - n) % 3))
		{
			printf("%d %d", (sum - n) / 3, i);
			break;
		}
	}
	return 0;
}