// AC
#include <cmath>
#include <cstdio>

bool check(int num)
{
	int m = sqrt(num);
	for (int i = 2; i <= m; ++i)
		if (!(num % i)) return false;
	return true;
}

int main()
{
	for (int i = 6; i <= 100; i += 2)
		for (int j = 2; true; ++j)
			if (check(j) && check(i - j))
			{
				printf("%d=%d+%d\n", i, j, i - j);
				break;
			}
	return 0;
}