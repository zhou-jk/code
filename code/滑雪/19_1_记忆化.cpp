// AC
#include <algorithm>
#include <cstdio>

using std::max;

const int N = 100, N_DIR = 4, dx[N_DIR] = {1, -1, 0, 0},
          dy[N_DIR] = {0, 0, 1, -1};
int a[N][N], f[N][N], n, m;

int dfs(int x, int y) {
    if (f[x][y]) return f[x][y];
    f[x][y] = 1;
    int tmp = 0;
    for (int i = 0; i < N_DIR; ++i) {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx >= 0 && tx < n && ty >= 0 && ty < m && a[tx][ty] < a[x][y])
            tmp = max(tmp, dfs(tx, ty));
    }
    return f[x][y] += tmp;
}

int main() {
    int ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!f[i][j]) ans = max(ans, dfs(i, j));
    printf("%d", ans);
    return 0;
}