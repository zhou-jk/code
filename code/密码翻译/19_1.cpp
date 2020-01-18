// AC
#include <cctype>
#include <cstdio>

const int LEN = 80;
char s[LEN + 1];

int main()
{
	gets(s);
	for (int i = 0; s[i]; ++i)
		if (isalpha(s[i]))
		{
			if (s[i] == 'z')
				putchar('a');
			else if (s[i] == 'Z')
				putchar('A');
			else
				putchar(s[i] + 1);
		}
		else
			putchar(s[i]);
	return 0;
}