// AC
#include <cstdio>

const int LEN = 8;
char s1[LEN + 1], s2[LEN + 1];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%s", s1, s2);
		if (s1[0] == s2[0])
			puts("Tie");
		else if ((s1[0] == 'R' && s2[0] == 'S')
				 || (s1[0] == 'S' && s2[0] == 'P')
				 || (s1[0] == 'P' && s2[0] == 'R'))
			puts("Player1");
		else
			puts("Player2");
	}
	return 0;
}