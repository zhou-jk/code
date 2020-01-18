// AC
#include <cctype>
#include <cstdio>
#include <cstring>

const int LEN = 50;
char s[LEN + 1];

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	for (int i = len - 1; ~i; --i)
	{
		char tmp;
		if (islower(s[i]))
		{
			tmp = toupper(s[i]);
			tmp = (tmp - 'A' + 3) % 26 + 'A';
		}
		else
		{
			tmp = tolower(s[i]);
			tmp = (tmp - 'a' + 3) % 26 + 'a';
		}
		putchar(tmp);
	}
	return 0;
}