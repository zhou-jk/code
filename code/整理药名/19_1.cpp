// AC
#include <cctype>
#include <cstdio>

const int LEN = 20;
char s[LEN + 1];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s);
		putchar(islower(s[0]) ? toupper(s[0]) : s[0]);
		for (int j = 1; s[j]; ++j)
			putchar(isupper(s[j]) ? tolower(s[j]) : s[j]);
		putchar('\n');
	}
}