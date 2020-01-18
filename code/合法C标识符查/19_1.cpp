// AC
#include <cctype>
#include <cstdio>

const int LEN = 20;
char s[LEN + 1];

int main()
{
	scanf("%s", s);
	for (int i = 0; s[i]; ++i)
		if (!isdigit(s[i]) && !isalpha(s[i]) && s[i] != '_')
		{
			puts("no");
			return 0;
		}
	if (isdigit(s[0]))
		puts("no");
	else
		puts("yes");
	return 0;
}