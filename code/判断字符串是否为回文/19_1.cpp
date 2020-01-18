// AC
#include <cstdio>
#include <cstring>

const int LEN = 100;
char str[LEN + 1];

int main()
{
	scanf("%s", str);
	int len = strlen(str), tmp = len >> 1;
	for (int i = 0; i < tmp; ++i)
		if (str[i] != str[len - 1 - i])
		{
			puts("no");
			return 0;
		}
	puts("yes");
	return 0;
}