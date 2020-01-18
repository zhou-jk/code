// AC
#include <cstdio>
#include <cstring>

const int LEN = 1000;
char s[LEN + 1];

int main()
{
	char *pWord;
	gets(s);
	pWord = strtok(s, " ");
	printf("%d", (int)strlen(pWord));
	pWord = strtok(NULL, " ");
	while (pWord != NULL)
	{
		printf(",%d", (int)strlen(pWord));
		pWord = strtok(NULL, " ");
	}
	return 0;
}