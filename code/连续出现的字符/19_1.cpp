// AC
#include <cstdio>

const int LEN = 2500;
char str[LEN + 1];

int main()
{
	char ch = 0;
	int k, cnt = 0;
	scanf("%d%s", &k, str);
	for (int i = 0; str[i]; ++i)
		if (str[i] == ch)
		{
			++cnt;
			if (cnt >= k)
			{
				putchar(ch);
				return 0;
			}
		}
		else
		{
			ch = str[i];
			cnt = 1;
		}
	puts("No");
	return 0;
}