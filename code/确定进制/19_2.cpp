// AC
#include <algorithm>
#include <cstdio>

using std::max;

const int LEN = 7;
char a[LEN + 1], b[LEN + 1], c[LEN + 1];

int max(char num[])
{
	int ret = 0;
	for (int i = 0; num[i]; ++i) ret = max(ret, num[i] - '0');
	return ret;
}

int solve(char num[], int base)
{
	int ret = 0;
	for (int i = 0; num[i]; ++i) ret = ret * base + num[i] - '0';
	return ret;
}

int main()
{
	scanf("%s%s%s", a, b, c);
	int ans = max(max(a), max(max(b), max(c)));
	for (; solve(a, ans) * solve(b, ans) != solve(c, ans); ++ans)
		if (ans > 40)
		{
			puts("0");
			return 0;
		};
	printf("%d", ans);
	return 0;
}