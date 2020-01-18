#include <cstdio>

const int N = 250, N_DIR = 4, dx[N_DIR] = {1, -1, 0, 0},
          dy[N_DIR] = {0, 0, 1, -1};
char a[N][N + 1];
int n, m, cnt1, cnt2;
bool vis[N][N], flag;

void dfs(int x, int y) {
    vis[x][y] = true;
    if (a[x][y] == 'k') ++cnt1;
    if (a[x][y] == 'v') ++cnt2;
    for (int i = 0; i < N_DIR; ++i) {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
            flag = true;
            continue;
        }
        if (!vis[tx][ty] && a[tx][ty] != '#') dfs(tx, ty);
    }
}

int main() {
    freopen("story.in", "r", stdin);
    freopen("story.out", "w", stdout);
    int ans1 = 0, ans2 = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%s", a[i]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!vis[i][j] && a[i][j] != '#') {
                flag = false;
                cnt1 = cnt2 = 0;
                dfs(i, j);
                if (flag) {
                    ans1 += cnt1;
                    ans2 += cnt2;
                } else {
                    if (cnt1 > cnt2)
                        ans1 += cnt1;
                    else
                        ans2 += cnt2;
                }
            }
    printf("%d %d", ans1, ans2);
    return 0;
}
