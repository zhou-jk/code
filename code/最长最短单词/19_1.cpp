// AC
#include <cstdio>
#include <cstring>

const int LEN_STR = 30000, LEN_WORD = 100;
char s[LEN_STR + 1], ans1[LEN_WORD + 1], ans2[LEN_WORD + 1];

int main()
{
	char *pWord;
	int lenAns1 = 0, lenAns2 = LEN_WORD;
	gets(s);
	pWord = strtok(s, " ,");
	while (pWord != NULL)
	{
		int lenWord = strlen(pWord);
		if (lenWord > lenAns1) strcpy(ans1, pWord), lenAns1 = lenWord;
		if (lenWord < lenAns2) strcpy(ans2, pWord), lenAns2 = lenWord;
		pWord = strtok(NULL, " ,");
	}
	printf("%s\n%s", ans1, ans2);
	return 0;
}