// AC
#include <cmath>
#include <cstdio>

const int LEN = 100;
char word[LEN + 1];
int vis[26];

bool check(int n)
{
	if (n < 2) return false;
	int m = sqrt(n);
	for (int i = 2; i <= m; ++i)
		if (!(n % i)) return false;
	return true;
}

int main()
{
	int max = 0, min = LEN;
	scanf("%s", word);
	for (int i = 0; word[i]; ++i) ++vis[word[i] - 'a'];
	for (int i = 0; i < 26; ++i)
	{
		if (vis[i] > max) max = vis[i];
		if (vis[i] && vis[i] < min) min = vis[i];
	}
	bool flag = check(max - min);
	puts(flag ? "Lucky Word" : "No Answer");
	printf("%d", flag ? max - min : 0);
	return 0;
}