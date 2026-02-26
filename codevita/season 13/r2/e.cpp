#include <bits/stdc++.h>
using namespace std;
struct Vec3 {
    int x, y, z;
    Vec3(int _x = 0, int _y = 0, int _z = 0) : x(_x), y(_y), z(_z) {}
    bool operator==(const Vec3& other) const { return x == other.x && y == other.y && z == other.z; }
    Vec3 operator+(const Vec3& other) const { return Vec3(x + other.x, y + other.y, z + other.z); }
    Vec3 operator-(const Vec3& other) const { return Vec3(x - other.x, y - other.y, z - other.z); }
    Vec3 operator*(int s) const { return Vec3(x * s, y * s, z * s); }
};
Vec3 cross(Vec3 a, Vec3 b) {
    return Vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}
struct Face {
    char id;
    string content;
    Vec3 normal;
    Vec3 up;
    bool visited;
};
map<char, Face> faces;
vector<string> grid(4);
void resolve_cube_orientation(int sr, int sc) {
    queue<pair<int, int>> q;
    q.push({sr, sc});
    char startId = grid[sr][sc];
    faces[startId].normal = Vec3(0, 0, 1);
    faces[startId].up = Vec3(0, 1, 0);
    faces[startId].visited = true;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        Vec3 N = faces[grid[r][c]].normal;
        Vec3 U = faces[grid[r][c]].up;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < 4 && nc >= 0 && nc < 4 && grid[nr][nc] != '.') {
                char nextId = grid[nr][nc];
                if (!faces[nextId].visited) {
                    faces[nextId].visited = true;
                    Vec3 nextN, nextU;
                    if (i == 0) {
                        nextN = U;
                        nextU = N * -1;
                    } else if (i == 1) {
                        nextN = U * -1;
                        nextU = N;
                    } else if (i == 2) {
                        Vec3 Left = cross(N, U);
                        nextN = Left;
                        nextU = U;
                    } else if (i == 3) {
                        Vec3 Right = cross(U, N);
                        nextN = Right;
                        nextU = U;
                    }
                    faces[nextId].normal = nextN;
                    faces[nextId].up = nextU;
                    q.push({nr, nc});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int sr = -1, sc = -1;
    for (int i = 0; i < 4; i++) {
        cin >> grid[i];
    }
    string str;
    cin >> str;
    vector<char> face_order;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] != '.') {
                if (sr == -1) {
                    sr = i, sc = j;
                }
                face_order.push_back(grid[i][j]);
                faces[grid[i][j]].id = grid[i][j];
                faces[grid[i][j]].visited = false;
            }
        }
    }
    for (int i = 0; i < 6; i++) {
        faces[face_order[i]].content = str.substr(i * 4, 4);
    }
    resolve_cube_orientation(sr, sc);
    string query;
    cin >> query;
    Vec3 cornerVec(0, 0, 0);
    for (char c : query) {
        cornerVec = cornerVec + faces[c].normal;
    }
    for (char fId : query) {
        Vec3 N = faces[fId].normal;
        Vec3 U = faces[fId].up;
        Vec3 R = cross(U, N);
        Vec3 candidates[4];
        candidates[0] = N + U - R;
        candidates[1] = N + U + R;
        candidates[2] = N - U - R;
        candidates[3] = N - U + R;
        for (int i = 0; i < 4; i++) {
            if (candidates[i] == cornerVec) {
                cout << faces[fId].content[i];
                break;
            }
        }
    }

    return 0;
}