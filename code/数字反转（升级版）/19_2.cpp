// AC
#include <cctype>
#include <cstdio>
#include <cstring>

const int LEN = 21;
char s[LEN + 1];

void solve(int l, int r)
{
	if (l > r) return;
	bool flag = false;
	for (; s[l] == '0' && l < r; ++l)
		;
	for (int i = r; i >= l; --i)
	{
		if (s[i] != '0') flag = true;
		if (flag) putchar(s[i]);
	}
	if (l == r && s[l] == '0') putchar('0');
}

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; ++i)
		if (!isdigit(s[i]))
		{
			solve(0, i - 1);
			putchar(s[i]);
			solve(i + 1, len - 1);
			return 0;
		}
	solve(0, len - 1);
	return 0;
}