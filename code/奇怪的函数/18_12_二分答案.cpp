// AC
#include <cmath>
#include <cstdio>

int n;

bool check(int num)
{
	if (log(num) / log(10) * num + 1 >= n) return true;
	return false;
}

int main()
{
	scanf("%d", &n);
	int l = 1, r = 1000000000;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	printf("%d", l);
	return 0;
}