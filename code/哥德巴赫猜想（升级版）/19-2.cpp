// AC
#include <cstdio>

const int MAX = 20000;
bool bPrime[MAX + 1];
int prime[MAX >> 1], nPrime;

int main()
{
	int num;
	scanf("%d", &num);
	bPrime[0] = bPrime[1] = true;
	for (int i = 2; i <= num; ++i)
	{
		if (!bPrime[i]) prime[nPrime++] = i;
		for (int j = 0; j < nPrime && prime[j] * i <= num; ++j)
		{
			bPrime[prime[j] * i] = true;
			if (!(i % prime[j])) break;
		}
	}
	for (int i = 0; i < nPrime; ++i)
		if (num - 2 - prime[i] > 1 && !bPrime[num - 2 - prime[i]])
		{
			printf("2 %d %d", prime[i], num - 2 - prime[i]);
			return 0;
		}
	for (int i = 0; i < nPrime; ++i)
		if (num - 3 - prime[i] > 1 && !bPrime[num - 3 - prime[i]])
		{
			printf("3 %d %d", prime[i], num - 3 - prime[i]);
			break;
		}
	return 0;
}