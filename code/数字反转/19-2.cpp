// AC
#include <cstdio>

int solve(int num)
{
	int ret = 0;
	while (num)
	{
		ret = ret * 10 + num % 10;
		num /= 10;
	}
	return ret;
}

int main()
{
	int num;
	scanf("%d", &num);
	printf("%d", solve(num));
	return 0;
}