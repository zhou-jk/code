// AC
#include <cmath>
#include <cstdio>

int solve(int num)
{
	int m = sqrt(num);
	int tmp = 1;
	for (int i = 2; i <= m; ++i)
		if (!(num % i)) tmp += i + num / i;
	if (m * m == num) tmp -= m;
	return tmp;
}

int main()
{
	for (int i = 2; true; ++i)
	{
		int tmp = solve(i);
		if (tmp != i && solve(tmp) == i)
		{
			printf("%d %d", i, tmp);
			break;
		}
	}
	return 0;
}