// AC
#include <cstdio>

const int L = 1, R = 1000;

int main()
{
	int ansA = 0, ansB = 0;
	for (int i = L; i <= R; ++i)
	{
		int tmp = i, cnt = 0;
		while (tmp)
		{
			cnt += tmp & 1 ? 1 : -1;
			tmp >>= 1;
		}
		if (cnt > 0)
			++ansA;
		else
			++ansB;
	}
	printf("%d %d", ansA, ansB);
	return 0;
}