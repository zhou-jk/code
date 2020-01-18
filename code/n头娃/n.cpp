// AC
#include <cstdio>
#include <queue>

using std::queue;

const int N = 1000, N_DIR = 4, dx[N_DIR] = {1, -1, 0, 0},
          dy[N_DIR] = {0, 0, 1, -1};
struct Node {
    int x, y;
};
int dis[N][N];
char tmp[N + 1];
bool vis[N][N];

int main() {
    freopen("n.in", "r", stdin);
    freopen("n.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    queue<Node> h;
    for (int i = 0; i < n; ++i) {
        scanf("%s", tmp);
        for (int j = 0; j < m; ++j)
            if (tmp[j] == '1') h.push(Node{i, j});
    }
    while (!h.empty()) {
        int x = h.front().x, y = h.front().y;
        h.pop();
        `1 if (vis[x][y]) continue;
        for (int i = 0; i < N_DIR; ++i) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && !vis[tx][ty]) {
                dis[tx][ty] = dis[x][y] + 1;
                h.push(Node{tx, ty});
                vis[tx][ty] = true;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) printf("%d ", dis[i][j]);
        putchar('\n');
    }
    return 0;
}
