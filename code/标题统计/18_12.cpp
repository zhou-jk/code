#include <cstdio>
#include <cstring>

const int LEN = 5;
char s[LEN + 1];

int main()
{
	freopen("title.in", "r", stdin);
	freopen("title.out", "w", stdout);
	int ans = 0;
	while (~scanf("%s", s)) ans += strlen(s);
	printf("%d", ans);
	return 0;
}