// AC
#include <cctype>
#include <cstdio>

const int LEN_STR = 1000000, LEN_WORD = 10;
char word[LEN_WORD + 1], str[LEN_STR + 1];

bool check(char a[], char b[])
{
	int i;
	for (i = 0; b[i]; ++i)
		if (tolower(a[i]) != tolower(b[i])) return false;
	return a[i] == ' ' || !a[i];
}

int main()
{
	int ans = 0, k = -1;
	gets(word);
	gets(str);
	for (int i = 0; str[i]; ++i)
		if ((!i || str[i - 1] == ' ') && check(str + i, word))
		{
			++ans;
			if (k == -1) k = i;
		}
	if (k == -1)
		puts("-1");
	else
		printf("%d %d", ans, k);
}