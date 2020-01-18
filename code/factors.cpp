#include <cstdio>
#include <cstring>
#include <cmath>

const int NUM = 100000, N1 = (int)sqrt(NUM) + 2;
bool is_prime[N1];
int prime[N1 / 3], n_prime, max, f[N1 / 3];

int calc(int num)
{
	int tmp = sqrt(num);
	if (tmp * tmp < num)
		tmp++;
	for (int i = 0; i < n_prime && prime[i] <= tmp; i++)
	{
		if (max < i)
			max = i;
		while (!(num % prime[i]))
		{
			f[i]++;
			num /= prime[i];
		}
	}
	return num;
}

int main()
{
	freopen("factors.in", "r", stdin);
	freopen("factors.out", "w", stdout);
	int t, a, b;
	memset(is_prime, true, sizeof is_prime);
	for (int i = 2; i <= N1; i++)
	{
		if (is_prime[i])
			prime[n_prime++] = i;
		for (int j = 0; j < n_prime && i * prime[j] <= N1; j++)
		{
			is_prime[i * prime[j]] = false;
			if (!(i % prime[j]))
				break;
		}
	}
	//printf("%d\n",n_prime);
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d%d", &a, &b);
		max = 0;
		memset(f, 0, sizeof f);
		int tmp1 = calc(a), tmp2 = calc(b);
		//printf("%d %d\n",tmp1,tmp2);
		int ans = 1;
		for (int j = 0; j <= max; j++)
		{
			if (tmp1 == prime[j])
			{
				tmp1 = 1;
				f[j]++;
			}
			if (tmp2 == prime[j])
			{
				tmp2 = 1;
				f[j]++;
			}
			ans *= f[j] + 1;
			//printf("%d %d\n",prime[j],f[j]);
		}
		if (tmp1 > 1 && tmp2 > 1)
			if (tmp1 == tmp2)
				ans *= 3;
			else
				ans *= 4;
		else if (tmp1 > 1 || tmp2 > 1)
			ans *= 2;
		printf("%d\n", ans);
	}
	return 0;
}