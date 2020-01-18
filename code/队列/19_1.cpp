// AC
#include <algorithm>
#include <cstdio>

using std::max;

const int LEN = 1000000;
char s[LEN];

int main()
{
	int s1 = 0, ans = 0;
	scanf("%s", s);
	for (int i = 0; s[i]; ++i)
		if (s[i] == 'M')
			++s1;
		else if (s1 > 0)
			ans = max(ans + 1, s1);
	printf("%d", ans);
	return 0;
}
