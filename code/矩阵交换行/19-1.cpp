// AC
#include <algorithm>
#include <cstdio>

using std::swap;

const int N = 5;
int s[N][N];

int main()
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) scanf("%d", &s[i][j]);
	int x, y;
	scanf("%d%d", &x, &y);
	swap(s[x - 1], s[y - 1]);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j) printf("%d ", s[i][j]);
		putchar('\n');
	}
	return 0;
}