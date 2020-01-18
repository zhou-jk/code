// AC
#include <cstdio>
#include <cstring>

const int LEN = 10;
char s[LEN + 1];

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	for (int i = len - 1; ~i; --i) putchar(s[i]);
	return 0;
}