// AC
#include <cmath>
#include <cstdio>

const int LEN = 2, L = 11;
int s[LEN], r, ans;

bool check(int n)
{
	if (n < 2) return false;
	int m = sqrt(n);
	for (int i = 2; i <= m; ++i)
		if (!(n % i)) return false;
	return true;
}

void dfs(int k)
{
	int a = 0, b;
	for (int i = 0; i < k; ++i) a = a * 10 + s[i];
	b = a;
	for (int i = k - 1; ~i; --i) a = a * 10 + s[i];
	for (int i = k - 2; ~i; --i) b = b * 10 + s[i];
	if (b > r) return;
	if (b >= L && check(b)) ++ans;
	if (a >= L && a <= r && check(a)) ++ans;
	for (int i = 0; i <= 9; ++i)
	{
		s[k] = i;
		dfs(k + 1);
	}
}

int main()
{
	scanf("%d", &r);
	for (s[0] = 1; s[0] <= 9; s[0] += 2) dfs(1);
	printf("%d", ans);
	return 0;
}