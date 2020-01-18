#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1000;
int c[N][N], max_x[N * N], min_x[N * N], max_y[N * N],
    min_y[N * N], vis[N + 1][N + 1], cnt, ans;
bool used[N * N], f[N * N];

inline int read()
{
    int X = 0;
    bool w = false;
    char ch = 0;
    while (ch < '0' || ch > '9') w |= ch == '-', ch = getchar();
    while (ch >= '0' && ch <= '9')
	X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
    return w ? -X : X;
}

void check(int x, int y)
{
    if (vis[x][y] > 1)
    {
	ans += f[c[x][y]];
	f[c[x][y]] = true;
	ans -= f[c[x][y]];
    }
}

int main()
{
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    memset(min_x, 0x3f, sizeof min_x);
    memset(min_y, 0x3f, sizeof min_y);
    int n;
    n = read();
    for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
	    c[i][j] = read() - 1;
	    if (c[i][j] >= 0)
	    {
		cnt -= used[c[i][j]];
		used[c[i][j]] = true;
		cnt += used[c[i][j]];
		max_x[c[i][j]] = max(max_x[c[i][j]], i);
		min_x[c[i][j]] = min(min_x[c[i][j]], i);
		max_y[c[i][j]] = max(max_y[c[i][j]], j);
		min_y[c[i][j]] = min(min_y[c[i][j]], j);
	    }
	}
    if (n > 1 && cnt == 1)
    {
	printf("%d", n * n - 1);
	return 0;
    }
    for (int i = 0; i < n * n; i++)
	if (used[i])
	{
	    vis[min_x[i]][min_y[i]]++;
	    vis[min_x[i]][max_y[i] + 1]--;
	    vis[max_x[i] + 1][min_y[i]]--;
	    vis[max_x[i] + 1][max_y[i] + 1]++;
	}
    ans = n * n;
    check(0, 0);
    for (int i = 1; i < n; i++)
    {
	vis[0][i] += vis[0][i - 1];
	vis[i][0] += vis[i - 1][0];
	check(0, i);
	check(i, 0);
    }
    for (int i = 1; i < n; i++)
	for (int j = 1; j < n; j++)
	{
	    vis[i][j] += vis[i - 1][j] + vis[i][j - 1]
			 - vis[i - 1][j - 1];
	    check(i, j);
	}
    printf("%d", ans);
    return 0;
}