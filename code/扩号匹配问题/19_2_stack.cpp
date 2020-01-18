// AC
#include <cstdio>
#include <cstring>

const int LEN = 100;
char s[LEN + 1], ans[LEN + 1];
int stk[LEN];

int main()
{
	while (scanf("%s", s) != EOF)
	{
		int len = strlen(s), top = 0;
		memset(ans, ' ', len);
		ans[len] = 0;
		for (int i = 0; i < len; ++i)
		{
			if (s[i] == '(') stk[top++] = i;
			if (s[i] == ')')
			{
				if (top)
					--top;
				else
					ans[i] = '?';
			}
		}
		for (int i = 0; i < top; ++i) ans[stk[i]] = '$';
		puts(s);
		puts(ans);
	}
	return 0;
}