#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int r, c;
};

struct StateKey {
    int r, c, dr, dc;
    bool operator==(const StateKey& o) const { return r == o.r && c == o.c && dr == o.dr && dc == o.dc; }
};

struct StateHasher {
    size_t operator()(StateKey const& s) const noexcept {
        return ((s.r * 131 + s.c) * 131 + (s.dr + 2)) * 131 + (s.dc + 2);
    }
};

bool inBounds(int r, int c, int R, int C) { return r >= 0 && r < R && c >= 0 && c < C; }

// 检查当前棋盘上是否还有砖块
bool hasBricks(const vector<vector<char>>& board) {
    for (auto& row : board)
        for (char ch : row)
            if (ch != '.') return true;
    return false;
}

/**
 * 依赖规则：
 *  - 同色 + 上下左右相邻 => 同一依赖组（互相依赖）
 *  - 垂直相邻：下面的砖依赖上面的砖（不论颜色）
 *    => 我们从“上砖”向“下砖”建有向边（上 -> 下）
 *
 * 传入击中的砖列表 hitBricks，做 BFS 链式扩散，得到所有要直接打碎的砖
 */
void collectDependents(const vector<vector<char>>& board, const vector<Cell>& hitBricks,
                       vector<vector<bool>>& vis, vector<Cell>& out) {
    int R = (int)board.size();
    int C = (int)board[0].size();
    vis.assign(R, vector<bool>(C, false));
    out.clear();

    queue<Cell> q;
    auto push = [&](int r, int c) {
        if (!inBounds(r, c, R, C)) return;
        if (board[r][c] == '.') return;
        if (vis[r][c]) return;
        vis[r][c] = true;
        q.push({r, c});
        out.push_back({r, c});
    };

    for (auto& cell : hitBricks) {
        if (inBounds(cell.r, cell.c, R, C) && board[cell.r][cell.c] != '.') push(cell.r, cell.c);
    }

    static const int dr4[4] = {-1, 1, 0, 0};
    static const int dc4[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        Cell cur = q.front();
        q.pop();
        int r = cur.r, c = cur.c;
        char color = board[r][c];

        // 同色 4 邻接（横竖）
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr4[k];
            int nc = c + dc4[k];
            if (inBounds(nr, nc, R, C) && board[nr][nc] == color && !vis[nr][nc]) {
                push(nr, nc);
            }
        }

        // 垂直依赖：下面的砖依赖上面的砖 => 上 -> 下
        int nr = r + 1, nc = c;
        if (inBounds(nr, nc, R, C) && board[nr][nc] != '.' && !vis[nr][nc]) {
            push(nr, nc);
        }
    }
}

/**
 * 掉落规则（“因失去连接而掉落的砖”）：
 *  - 认为顶行（row=0）的砖和与之连通的所有砖是“被支撑”的
 *  - 连通关系：任意颜色，上下左右 4 邻接
 *  - 其余所有砖都认为是掉落砖
 */
void collectFloating(const vector<vector<char>>& board, vector<vector<bool>>& vis, vector<Cell>& floating) {
    int R = (int)board.size();
    int C = (int)board[0].size();
    vis.assign(R, vector<bool>(C, false));
    floating.clear();

    static const int dr4[4] = {-1, 1, 0, 0};
    static const int dc4[4] = {0, 0, -1, 1};

    queue<Cell> q;
    // 顶行作为“天花板支撑”
    for (int c = 0; c < C; ++c) {
        if (board[0][c] != '.') {
            vis[0][c] = true;
            q.push({0, c});
        }
    }

    while (!q.empty()) {
        Cell cur = q.front();
        q.pop();
        int r = cur.r, c = cur.c;
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr4[k];
            int nc = c + dc4[k];
            if (inBounds(nr, nc, R, C) && board[nr][nc] != '.' && !vis[nr][nc]) {
                vis[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (board[r][c] != '.' && !vis[r][c]) {
                floating.push_back({r, c});
            }
        }
    }
}

/**
 * 模拟一次“从当前状态出发，直到下一次击中砖”的过程
 *
 * 输入/输出：
 *  - board：棋盘（只读）
 *  - R,C：行列
 *  - r,c：球当前所在位置（cell 中心），会被更新
 *  - dr,dc：方向（-1/+1），会被更新为碰撞后的方向
 *
 * 返回：
 *  - bricksHit：本次碰撞真正被“第一时间打到”的砖（1 个或者 2 个）
 *  - hit == false：说明球在当前局面下再也打不到砖（进入循环），可以结束
 */
struct HitResult {
    bool hit;
    vector<Cell> bricksHit;
};

HitResult simulateUntilHit(const vector<vector<char>>& board, int R, int C, int& r, int& c, int& dr,
                           int& dc) {
    HitResult res;
    res.hit = false;
    res.bricksHit.clear();

    unordered_set<StateKey, StateHasher> visited;

    while (true) {
        StateKey key{r, c, dr, dc};
        if (visited.count(key)) {
            // 状态重复，说明在这个局面下球进了一个死循环，再也不会打到砖
            res.hit = false;
            res.bricksHit.clear();
            return res;
        }
        visited.insert(key);

        int vr = r + dr;     // 垂直方向要去到的行
        int hc = c + dc;     // 水平方向要去到的列
        int drc_r = r + dr;  // 对角格子行
        int drc_c = c + dc;  // 对角格子列

        bool hitVertWall = (vr < 0 || vr >= R);
        bool hitHorWall = (hc < 0 || hc >= C);

        bool hitVertBrick = false;
        bool hitHorBrick = false;
        vector<Cell> bricks;

        // 垂直方向：先看是不是撞墙，再看是不是撞砖
        if (!hitVertWall) {
            if (board[vr][c] != '.') {
                hitVertBrick = true;
                bricks.push_back({vr, c});
            }
        }

        // 水平方向：同理
        if (!hitHorWall) {
            if (board[r][hc] != '.') {
                hitHorBrick = true;
                // 防重复（虽然通常不会重复）
                bool duplicate = false;
                for (auto& b : bricks)
                    if (b.r == r && b.c == hc) {
                        duplicate = true;
                        break;
                    }
                if (!duplicate) bricks.push_back({r, hc});
            }
        }

        bool hitVert = hitVertWall || hitVertBrick;
        bool hitHor = hitHorWall || hitHorBrick;

        if (!hitVert && !hitHor) {
            // 没有在上下左右方向撞到墙或砖，检查对角格子
            if (board[drc_r][drc_c] != '.') {
                // 纯对角撞砖 => 视为“角撞”，方向整体反向
                bricks.push_back({drc_r, drc_c});
                dr = -dr;
                dc = -dc;
                res.hit = true;
                res.bricksHit = bricks;
                return res;
            } else {
                // 什么都没撞，直接移动一个对角格子
                r = drc_r;
                c = drc_c;
                continue;
            }
        } else {
            // 至少在垂直 / 水平方向撞到了“东西”（墙或者砖）
            if (hitVert) dr = -dr;
            if (hitHor) dc = -dc;

            if (!bricks.empty()) {
                // 撞到了砖（可能 1 块，也可能 2 块）
                res.hit = true;
                res.bricksHit = bricks;
                return res;
            } else {
                // 只撞墙没撞砖，位置不变，只改变方向，继续模拟
                continue;
            }
        }
    }
}

/**
 * 整体模拟 K 次“击中砖”的过程，返回整个过程中挡板出现过的最大长度
 */
int simulateGame(vector<vector<char>> board,  // 初始棋盘，内部会拷贝
                 int R, int C, int M, const unordered_map<char, int>& colorScore, int startCol, int paddleLen,
                 int minLen, int K) {
    int maxPaddle = paddleLen;

    // 初始球位置：挡板上方一格（R-2，startCol），方向 45° 左上
    int r = R - 2;
    int c = startCol;
    int dr = -1, dc = -1;

    vector<vector<bool>> vis;
    vector<Cell> depCells, floatingCells;

    for (int bounce = 0; bounce < K; ++bounce) {
        if (!hasBricks(board)) break;

        HitResult h = simulateUntilHit(board, R, C, r, c, dr, dc);
        if (!h.hit || h.bricksHit.empty()) {
            // 后面再也打不到砖了
            break;
        }

        // 1. 按依赖规则打碎“依赖组”
        collectDependents(board, h.bricksHit, vis, depCells);
        long long score = 0;
        for (auto& cell : depCells) {
            char ch = board[cell.r][cell.c];
            auto it = colorScore.find(ch);
            if (it != colorScore.end()) score += it->second;
            board[cell.r][cell.c] = '.';
        }

        // 2. 由于支撑断开而“掉落”的砖
        collectFloating(board, vis, floatingCells);
        for (auto& cell : floatingCells) {
            char ch = board[cell.r][cell.c];
            auto it = colorScore.find(ch);
            if (it != colorScore.end()) score += it->second;
            board[cell.r][cell.c] = '.';
        }

        // 3. 根据 hit score 调整挡板长度
        if (score > 0) {
            if (paddleLen + 2 <= C) paddleLen += 2;
        } else if (score < 0) {
            if (paddleLen - 2 >= minLen) paddleLen -= 2;
        }
        if (paddleLen > maxPaddle) maxPaddle = paddleLen;
    }

    return maxPaddle;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    if (!(cin >> R >> C)) {
        return 0;
    }
    int M;
    cin >> M;

    vector<vector<char>> board(R, vector<char>(C, '.'));

    // 读入前 M 行砖图
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < C; ++j) {
            string tok;
            cin >> tok;
            board[i][j] = tok[0];  // '.' 或 'A'~'Z'
        }
    }

    // 读入一行颜色字母
    string line;
    getline(cin, line);  // 把上一行残留的换行吃掉

    getline(cin, line);
    stringstream ss(line);
    vector<char> colors;
    char ch;
    while (ss >> ch) {
        colors.push_back(ch);
    }

    // 读入对应的分值
    getline(cin, line);
    stringstream ss2(line);
    vector<int> scores;
    int v;
    while (ss2 >> v) {
        scores.push_back(v);
    }

    unordered_map<char, int> colorScore;
    for (size_t i = 0; i < colors.size() && i < scores.size(); ++i) {
        colorScore[colors[i]] = scores[i];
    }

    int startCol;
    cin >> startCol;
    int curLen, minLen;
    cin >> curLen >> minLen;
    int K;
    cin >> K;

    int ans = simulateGame(board, R, C, M, colorScore, startCol, curLen, minLen, K);
    cout << ans << "\n";
    return 0;
}
