// AC
#include <cstdio>

const int LEN = 50;
char s[LEN + 1];

int main()
{
	int n;
	scanf("%d%s", &n, s);
	for (int i = 0; s[i]; ++i) putchar((s[i] - 'a' + n) % 26 + 'a');
	return 0;
}