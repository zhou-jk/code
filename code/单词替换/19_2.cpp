// AC
#include <cstdio>
#include <cstring>

const int LEN_STR = 200, LEN_WORD = 100;
char str[LEN_STR + 1], a[LEN_WORD + 1], b[LEN_WORD + 1];

int main()
{
	gets(str);
	scanf("%s%s", a, b);
	int lenA = strlen(a);
	for (int i = 0; str[i]; ++i)
		if ((!i || str[i - 1] == ' ')
			&& (str[i + lenA] == ' ' || !str[i + lenA])
			&& !strncmp(str + i, a, lenA))
		{
			printf(b);
			i += lenA - 1;
		}
		else
			putchar(str[i]);
	return 0;
}