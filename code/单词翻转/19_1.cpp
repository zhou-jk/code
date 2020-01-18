// AC
#include <cstdio>

const int LEN = 500;
char str[LEN + 1], word[LEN + 1];
int lenWord;

void out()
{
	for (int i = lenWord - 1; ~i; --i) putchar(word[i]);
	lenWord = 0;
}

int main()
{
	gets(str);
	for (int i = 0; str[i]; ++i)
		if (str[i] == ' ')
		{
			out();
			putchar(' ');
		}
		else
			word[lenWord++] = str[i];
	out();
	return 0;
}