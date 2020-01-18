// AC
#include <cctype>
#include <cstdio>

const int N = 4, LEN = 100;
char s[LEN + 1];
int vis[26];

int main()
{
	int max = 0;
	for (int i = 0; i < N; ++i)
	{
		gets(s);
		for (int j = 0; s[j]; ++j)
			if (isupper(s[j])) ++vis[s[j] - 'A'];
	}
	for (int i = 0; i < 26; ++i)
		if (vis[i] > max) max = vis[i];
	for (int i = max; i; --i)
	{
		bool flag = false;
		for (int j = 0; j < 26; ++j)
		{
			if (flag) putchar(' ');
			flag = true;
			putchar(vis[j] >= i ? '*' : ' ');
		}
		putchar('\n');
	}
	bool flag = false;
	for (char i = 'A'; i <= 'Z'; ++i)
	{
		if (flag) putchar(' ');
		flag = true;
		putchar(i);
	}
	return 0;
}