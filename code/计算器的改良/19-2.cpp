// AC
#include <algorithm>
#include <cctype>
#include <cstdio>

using std::max;

const int LEN = 10000;
char s[LEN + 1];

int main()
{
	char var;
	int a = 1, b = 0, c = -1, d = 0, e = 0;
	scanf("%s", s);
	for (int i = 0; s[i]; ++i)
		if (isdigit(s[i]))
			b = b * 10 + s[i] - '0';
		else
		{
			if (isalpha(s[i]))
			{
				var = s[i];
				d += -c * a * max(b, 1);
			}
			else
			{
				e += c * a * b;
				if (s[i] == '-') a = -1;
				if (s[i] == '+') a = 1;
				if (s[i] == '=') a = c = 1;
			}
			b = 0;
		}
	e += c * a * b;
	double ans = (double)e / d;
	if (e == 0) ans = 0;
	printf("%c=%.3f", var, ans);
	return 0;
}