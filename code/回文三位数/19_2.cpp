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
	for (int i = 1; i <= 9; ++i)
		for (int j = 0; j <= 9; ++j)
			if (check(i * 100 + j * 10 + i))
				printf("%d\n", i * 100 + j * 10 + i);
	return 0;
}