// AC
#include <cstdio>

const int LEN = 1000;
char s[LEN + 1];
int cnt[26];

int main()
{
	scanf("%s", s);
	for (int i = 0; s[i]; ++i) ++cnt[s[i] - 'a'];
	int ans = 0;
	for (int i = 1; i < 26; ++i)
		if (cnt[i] > cnt[ans]) ans = i;
	printf("%c %d", 'a' + ans, cnt[ans]);
	return 0;
}