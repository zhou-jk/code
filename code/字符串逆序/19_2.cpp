// AC
#include <cstdio>
#include <cstring>

const int LEN = 1000;
char s[LEN + 1];

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	for (int i = len - 2; ~i; --i) putchar(s[i]);
	return 0;
}