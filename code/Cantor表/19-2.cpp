// AC
#include <cstdio>

int main()
{
	int n, tmp = 0;
	scanf("%d", &n);
	for (int i = 1; true; ++i)
	{
		tmp += i;
		if (tmp >= n)
		{
			int tmp1 = tmp - n;
			if (i & 1)
				printf("%d/%d", 1 + tmp1, i - tmp1);

			else
				printf("%d/%d", i - tmp1, 1 + tmp1);
			break;
		}
	}
	return 0;
}