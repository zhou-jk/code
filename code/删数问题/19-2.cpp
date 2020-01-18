// AC
#include <cstdio>
#include <cstring>

const int LEN = 240;
char s[LEN + 1];

int main()
{
	int n, k = 0, len, m;
	scanf("%s%d", s, &n);
	len = strlen(s);
	m = len - n;
	bool flag = false;
	while (m--)
	{
		int tmp = k;
		for (int i = k + 1; i <= k + n; ++i)
			if (s[i] < s[tmp]) tmp = i;
		if (s[tmp] - '0') flag = true;
		if (flag) putchar(s[tmp]);
		n -= tmp - k;
		k = tmp + 1;
	}
	if (!flag) putchar('0');
	return 0;
}