// AC
#include <cstdio>

const int LEN = 1000;
char str[LEN + 1];

int main()
{
	char ch = 0;
	int cnt = 0;
	scanf("%s", str);
	for (int i = 0; str[i]; ++i)
		if (str[i] == ch)
			++cnt;
		else
		{
			if (cnt) printf("%d%c", cnt, ch);
			cnt = 1;
			ch = str[i];
		}
	printf("%d%c", cnt, ch);
	return 0;
}