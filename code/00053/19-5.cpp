// AC
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>

using std::min;
using std::pair;
using std::queue;

const int N = 30, N_DIR = 4, dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
struct Edge {
    int v, dis, next;
} edge[N * N * N_DIR * N_DIR];
int a[N][N], step[N][N], head[N * N * N_DIR], dis[N * N * N_DIR], n, m, cnt;
bool vis[N * N * N_DIR];

inline int GetId(int x, int y, int dir) { return (x * m + y) * N_DIR + dir; }

inline bool able(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && a[x][y];
}

int bfs(int x1, int y1, int x2, int y2, int x3, int y3) {
    if (x1 == x2 && y1 == y2) return 0;
    queue<pair<int, int> > q;
    q.push(pair<int, int>(x1, y1));
    memset(step, 127, sizeof step);
    step[x1][y1] = 0;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < N_DIR; ++i) {
            int tx = x + dx[i], ty = y + dy[i];
            if (!able(tx, ty) || (tx == x3 && ty == y3)) continue;
            if (step[x][y] + 1 < step[tx][ty]) {
                step[tx][ty] = step[x][y] + 1;
                if (tx == x2 && ty == y2) return step[x2][y2];
                q.push(pair<int, int>(tx, ty));
            }
        }
    }
    return -1;
}

inline void AddEdge(int u, int v, int dis) {
    edge[cnt].v = v;
    edge[cnt].dis = dis;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

inline void AddUndiEdge(int u, int v, int dis) {
    // printf("&%d %d %d\n", u, v, dis);
    AddEdge(u, v, dis);
    AddEdge(v, u, dis);
}

int spfa(int x1, int y1, int x2, int y2, int x3, int y3) {
    // printf("%d %d %d %d %d %d\n", x1, y1, x2, y2, x3, y3);
    if (x2 == x3 && y2 == y3) return 0;
    queue<int> q;
    memset(dis, 127, sizeof dis);
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < N_DIR; ++i) {
        int tx = x2 + dx[i], ty = y2 + dy[i];
        if (able(tx, ty)) {
            int tmp = bfs(x1, y1, tx, ty, x2, y2);
            if (~tmp) {
                int id = GetId(x2, y2, i);
                dis[id] = tmp;
                if (!vis[id]) {
                    vis[id] = true;
                    q.push(id);
                }
            }
        }
    }
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        vis[k] = false;
        for (int i = head[k]; ~i; i = edge[i].next) {
            int v = edge[i].v;
            if (dis[k] + edge[i].dis < dis[v]) {
                dis[v] = dis[k] + edge[i].dis;
                // printf("$%d %d %d %d\n", k, v, dis[k], dis[v]);
                vis[v] = true;
                q.push(v);
            }
        }
    }
    int ans = dis[GetId(x3, y3, 0)];
    for (int i = 1; i < N_DIR; ++i) ans = min(ans, dis[GetId(x3, y3, i)]);
    return ans > 1E9 ? -1 : ans;
}

int main() {
    int q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
    memset(head, -1, sizeof head);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j])
                for (int k = 0; k < N_DIR; ++k) {
                    int tx1 = i + dx[k], ty1 = j + dy[k];
                    if (able(tx1, ty1))
                        for (int p = k + 1; p < N_DIR; ++p) {
                            int tx2 = i + dx[p], ty2 = j + dy[p];
                            if (able(tx2, ty2)) {
                                int dis = bfs(tx1, ty1, tx2, ty2, i, j);
                                if (~dis)
                                    AddUndiEdge(GetId(i, j, k), GetId(i, j, p),
                                                dis);
                            }
                        }
                }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j]) {
                if (able(i + 1, j))
                    AddUndiEdge(GetId(i, j, 2), GetId(i + 1, j, 0), 1);
                if (able(i, j + 1))
                    AddUndiEdge(GetId(i, j, 1), GetId(i, j + 1, 3), 1);
            }
    while (q--) {
        int ex, ey, sx, sy, tx, ty;
        scanf("%d%d%d%d%d%d", &ex, &ey, &sx, &sy, &tx, &ty);
        printf("%d\n", spfa(ex - 1, ey - 1, sx - 1, sy - 1, tx - 1, ty - 1));
    }
    return 0;
}