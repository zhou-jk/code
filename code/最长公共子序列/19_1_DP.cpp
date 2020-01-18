// AC
#include <algorithm>
#include <cstdio>
#include <cstring>

using std::max;

const int LEN = 1000;
char s1[LEN + 1], s2[LEN + 1];
int f[LEN + 1][LEN + 1];

int main()
{
	scanf("%s%s", s1, s2);
	int len1 = strlen(s1), len2 = strlen(s2);
	for (int i = 0; s1[i]; ++i)
		for (int j = 0; s2[j]; ++j)
		{
			if (s1[i] == s2[j]) f[i + 1][j + 1] = f[i][j] + 1;
			f[i + 1][j + 1] =
				max(f[i + 1][j + 1], max(f[i][j + 1], f[i + 1][j]));
		}
	printf("%d", f[len1][len2]);
	return 0;
}