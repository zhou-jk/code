// AC
#include <cstdio>
#include <cstring>

const int LEN = 100;
char s[LEN + 1];

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 1; i < len; ++i) putchar(s[i - 1] + s[i]);
	putchar(s[0] + s[len - 1]);
	return 0;
}