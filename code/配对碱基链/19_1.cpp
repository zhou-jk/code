// AC
#include <cstdio>

const int LEN = 255;
char s[LEN + 1];

int main()
{
	scanf("%s", s);
	for (int i = 0; s[i]; ++i) switch (s[i])
		{
			case 'A': putchar('T'); break;
			case 'G': putchar('C'); break;
			case 'T': putchar('A'); break;
			case 'C': putchar('G'); break;
		}
	return 0;
}