// AC
#include <cctype>
#include <cstdio>

const int LEN = 255;
char s[LEN + 1];

int main()
{
	int ans = 0;
	gets(s);
	for (int i = 0; s[i]; ++i) ans += isdigit(s[i]);
	printf("%d", ans);
	return 0;
}