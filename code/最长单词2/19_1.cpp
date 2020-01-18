// AC
#include <cstdio>
#include <cstring>

const int LEN=500;
char s[LEN + 1], ans[LEN + 1];

int main()
{
	char *pWord;
	int lenAns = 0;
	gets(s);
	pWord = strtok(s, " .");
	while (pWord != NULL)
	{
		int lenWord = strlen(pWord);
		if (lenWord > lenAns) strcpy(ans, pWord), lenAns = lenWord;
		pWord = strtok(NULL, " .");
	}
	printf("%s", ans);
	return 0;
}