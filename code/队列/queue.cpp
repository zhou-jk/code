// AC
#include <bits/stdc++.h>

using namespace std;

const int LEN = 1000010;
char s[LEN];

int main()
{
	freopen("queue.in", "r", stdin);
	freopen("queue.out", "w", stdout);
	int s1 = 0, s2 = 0, ans = 0;
	bool flag = true;
	scanf("%s", s);
	for (int i = 0; s[i]; ++i)
		if (s[i] == 'M')
			s2 = max(s2 - 1, 0), flag = false;
		else
			ans = max(ans, flag ? 0 : i + s2 - s1), ++s1,
			s2 = flag ? s2 : s2 + 1;
	printf("%d", ans);
	return 0;
}
