// AC
#include <cstdio>

const int LEN = 13;
char s[LEN + 1];

int main()
{
	scanf("%s", s);
	int tmp = ((s[0] - '0') * 1 + (s[2] - '0') * 2 + (s[3] - '0') * 3
			   + (s[4] - '0') * 4 + (s[6] - '0') * 5 + (s[7] - '0') * 6
			   + (s[8] - '0') * 7 + (s[9] - '0') * 8 + (s[10] - '0') * 9)
			  % 11;
	char ch;
	if (tmp == 10)
		ch = 'X';
	else
		ch = tmp + '0';
	if (ch == s[12])
		puts("Right");
	else
	{
		s[12] = ch;
		puts(s);
	}
	return 0;
}