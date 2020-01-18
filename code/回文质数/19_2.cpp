// AC
#include <algorithm>
#include <cmath>
#include <cstdio>

using std::sort;

const int LEN = 5;
int s[LEN], l, r, ans[30000], cnt;

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
	if (b >= l && check(b)) ans[cnt++] = b;
	if (a >= l && a <= r && check(a)) ans[cnt++] = a;
	for (int i = 0; i <= 9; ++i)
	{
		s[k] = i;
		dfs(k + 1);
	}
}

int main()
{
	scanf("%d%d", &l, &r);
	for (s[0] = 1; s[0] <= 9; s[0] += 2) dfs(1);
	sort(ans, ans + cnt);
	for (int i = 0; i < cnt; ++i) printf("%d\n", ans[i]);
	return 0;
}