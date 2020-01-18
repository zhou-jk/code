// AC
#include <cstdio>

const int LEN = 100000;
char s[LEN + 1];
int cnt[26];

int main()
{
	scanf("%s", s);
	for (int i = 0; s[i]; ++i) ++cnt[s[i] - 'a'];
	for (int i = 0; s[i]; ++i)
		if (cnt[s[i] - 'a'] == 1)
		{
			putchar(s[i]);
			return 0;
		}
	puts("no");
	return 0;
}