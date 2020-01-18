// AC
#include <cstdio>
#include <cstring>

const int LEN = 32;
char s[LEN + 1];

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	if (len > 2
		&& ((s[len - 2] == 'e' && s[len - 1] == 'r')
			|| (s[len - 2] == 'l' && s[len - 1] == 'y')))
		s[len - 2] = 0;
	if (len > 3 && s[len - 3] == 'i' && s[len - 2] == 'n' && s[len - 1] == 'g')
		s[len - 3] = 0;
	printf("%s", s);
	return 0;
}