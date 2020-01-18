// AC
#include <cstdio>
#include <cstring>

const int N = 1000;
bool map[30000][30000];
int ans;

void solve(int x, int y)
{
	++ans;
	printf("%d %d\n", x, y);
	if (map[x + 1][y]) solve(x + 1, y);
	if (map[x][y + 1]) solve(x, y + 1);
	map[x + 1][y] = map[x][y + 1] = true;
	map[x][y] = false;
}

int main()
{
	// freopen("game.in", "r", stdin);
	// freopen("game.out", "w", stdout);
	int n;
	scanf("%d", &n);
	/*if (n >= 3)
	{
		puts("-1");
		return 0;
	}*/
	// memset(map, 0, sizeof map);
	map[0][0] = true;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= i; ++j)
			if (map[j][i - j]) solve(j, i - j);
	printf("%d", ans);
	return 0;
}