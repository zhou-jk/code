// AC
#include <cstdio>
#include <queue>

using std::priority_queue;

const int N = 1000, N_DIR = 4, dx[N_DIR] = {1, -1, 0, 0},
          dy[N_DIR] = {0, 0, 1, -1};
struct Node {
    int x, y, dis;
    bool operator<(const Node &b) const { return dis > b.dis; }
};
int dis[N][N];
char tmp[N + 1];
bool vis[N][N];

int main() {
    freopen("n.in", "r", stdin);
    freopen("n.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    priority_queue<Node> h;
    for (int i = 0; i < n; ++i) {
        scanf("%s", tmp);
        for (int j = 0; j < m; ++j) {
            dis[i][j] = tmp[j] == '1' ? 0 : 100000000;
            if (tmp[j] == '1') h.push(Node{i, j, 0});
        }
    }
    while (!h.empty()) {
        int x = h.top().x, y = h.top().y;
        h.pop();
        if (vis[x][y]) continue;
        vis[x][y] = true;
        for (int i = 0; i < N_DIR; ++i) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m &&
                dis[x][y] + 1 < dis[tx][ty]) {
                dis[tx][ty] = dis[x][y] + 1;
                h.push(Node{tx, ty, dis[tx][ty]});
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) printf("%d ", dis[i][j]);
        putchar('\n');
    }
    return 0;
}
