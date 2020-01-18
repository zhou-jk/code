#include <cstdio>
long long n, p, s, id, a[101], b[101], e[100001], ru[100001], vis[100001];
long long calc()
{
	for (int i = 1; i <= n; i++)
		b[i] = a[i];
	for (int i = 1; i <= n; i++)
		if (a[i])
			b[(i + 1) % n + (i == n - 1) * n] ^= 1;
	s = 0;
	for (int i = 1; i <= n; i++)
		s = s * 2 + b[i];
	ru[s]++;
	return s;
}
void dfs(long long k, long long sh)
{
	if (vis[k])
	{
		if (p < vis[k])
			return;
		s = k;
		p -= vis[k] - 1;
		p %= sh - vis[k];
		return;
	}
	vis[k] = sh;
	dfs(e[k], sh + 1);
}
int main()
{
	freopen("blink.in", "r", stdin);
	freopen("blink.out", "w", stdout);
	scanf("%lld%lld", &n, &p);
	while (!a[0])
	{
		e[id++] = calc();
		a[s = n]++;
		while (a[s] > 1)
		{
			a[s] -= 2;
			a[--s]++;
		}
	}
	s = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &id);
		s = s * 2 + id;
	}
	dfs(s, 1);
	for (int i = 1; i <= p; i++)
		s = e[s];
	for (int i = 1; i <= n; i++)
	{
		a[i] = s % 2;
		s /= 2;
	}
	for (int i = n; i; i--)
		printf("%lld\n", a[i]);
}
