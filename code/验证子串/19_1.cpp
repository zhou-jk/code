// AC
#include <cstdio>
#include <cstring>

const int LEN = 200;
char s1[LEN + 1], s2[LEN + 2];

int main()
{
	scanf("%s%s", s1, s2);
	if (strstr(s1, s2) != NULL)
		printf("%s is substring of %s", s2, s1);
	else if (strstr(s2, s1) != NULL)
		printf("%s is substring of %s", s1, s2);
	else
		puts("No substring");
	return 0;
}