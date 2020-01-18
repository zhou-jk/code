// AC
#include <cctype>
#include <cstdio>
#include <cstring>

const int LEN_KEY = 100, LEN_STR = 1000;
char key[LEN_KEY], str[LEN_STR];

int main()
{
	scanf("%s%s", key, str);
	int lenKey = strlen(key);
	for (int i = 0; str[i]; ++i)
	{
		char ch = islower(str[i]) ? 'a' : 'A';
		putchar(((str[i] - ch - (tolower(key[i % lenKey]) - 'a')) % 26 + 26)
					% 26
				+ ch);
	}
	return 0;
}