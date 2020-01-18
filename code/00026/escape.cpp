#include <algorithm>
#include <cstdio>
#include <queue>

using std::min;
using std::queue;

struct Node {
    int x1, y1, x2, y2, t;
};

const int N = 20, N_DIR = 4, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char a[N][N + 1], d[N_DIR + 1];
int dd[N_DIR], f[N][N][N][N];
bool vis[N][N][N][N];
queue<Node> q;

int cover(char dir) {
    int ret;
    switch (dir) {
        case 'N':
            ret = 0;
            break;
        case 'S':
            ret = 1;
            break;
        case 'W':
            ret = 2;
            break;
        case 'E':
            ret = 3;
            break;
        default:
            ret = -1;
            break;
    }
    return ret;
}

void Add(int x1, int y1, int x2, int y2, int t) {
    if (!vis[x1][y1][x2][y2]) {
        q.push(Node{x1, y1, x2, y2, t});
        vis[x1][y1][x2][y2] = true;
    }
}

int main() {
    freopen("escape.in", "r", stdin);
    freopen("escape.out", "w", stdout);
    int n, m, x1, y1, x2, y2, ans = 256, c;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 'P') {
                x1 = i;
                y1 = j;
            }
            if (a[i][j] == 'H') {
                x2 = i;
                y2 = j;
            }
        }
    }
    scanf("%s", d);
    for (int i = 0; i < N_DIR; ++i) dd[i] = cover(d[i]);
    Add(x1, y1, x2, y2, 0);
    while (!q.empty()) {
        Node s = q.front();
        if (s.t > 255) {
            puts("Impossible");
            return 0;
        }
        q.pop();
        for (int i = 0; i < N_DIR; ++i) {
            int tx1 = s.x1 + dx[i], ty1 = s.y1 + dy[i];
            if (a[tx1][ty1] != '#' && a[tx1][ty1] != '!') {
                int tx2 = s.x2 + dx[dd[i]], ty2 = s.y2 + dy[dd[i]];
                if (a[tx2][ty2] != '#' && a[tx2][ty2] != '!') {
                    Add(tx1, ty1, tx2, ty2, s.t + 1);
                } else if (a[tx2][ty2] == '#')
                    Add(tx1, ty1, s.x2, s.y2, s.t + 1);
            }
        }
    }
    printf("%d", ans);
    return 0;
}
