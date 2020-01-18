// AC
#include <cctype>
#include <cstdio>

const int LEN = 100;
char s[LEN + 1];

int main()
{
	gets(s);
	for (int i = 0; s[i]; ++i)
		if (islower(s[i]))
			putchar(toupper(s[i]));
		else
			putchar(s[i]);
	return 0;
}