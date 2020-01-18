#include <cstdio>

const int LEN = 200000;
char s[LEN + 1];

int main()
{
	freopen("i.in", "r", stdin);
	freopen("i.out", "w", stdout);
	int ans = 1, dx = 0, dy = 0;
	scanf("%s", s);
	for (int i = 0; s[i]; ++i)
	{
		bool flag = false;
		switch (s[i])
		{
		case 'U':
			flag = dy == 1;
			dy = -1;
			break;
		case 'D':
			flag = dy == -1;
			dy = 1;
			break;
		case 'L':
			flag = dx == 1;
			dx = -1;
			break;
		case 'R':
			flag = dx == -1;
			dx = 1;
			break;
		}
		if (flag)
		{
			++ans;
			if (s[i] == 'U' || s[i] == 'D')
				dx = 0;
			else
				dy = 0;
		}
	}
	printf("%d", ans);
	return 0;
}
