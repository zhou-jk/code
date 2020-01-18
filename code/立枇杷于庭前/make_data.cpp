#include <cstdio>
#include <cstdlib>
#include <ctime>

const int M = 100000;

int main()
{
	freopen("white.in", "w", stdout);
	srand(time(NULL));
	int n = rand() % 30 + 1;
	printf("%d\n", n);
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		if (M - sum)
			tmp = rand() % (M - sum) + 1;
		else
			tmp = 0;
		sum += tmp;
		printf("%d ", tmp);
	}
	return 0;
}