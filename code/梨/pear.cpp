#include <cctype>
#include <cstdio>

const int LEN = 100000;
char s[LEN + 5], p[5] = "pear";

int main()
{
	freopen("pear.in", "r", stdin);
	freopen("pear.out", "w", stdout);
	scanf("%s", s);
	for (int i = 0; s[i]; ++i)
	{
		bool flag = true;
		for (int j = 0; p[j]; ++j)
			if (tolower(s[i + j]) != p[j])
			{
				flag = false;
				break;
			}
		if (flag)
		{
			printf("%s", "apple");
			i += 3;
		}
		else
			putchar(s[i]);
	}
	return 0;
}