#include <bits/stdc++.h>
using namespace std;
constexpr int MAXW = 20005;
constexpr int MAXH = 505;
char canvas[MAXH][MAXW];
int max_y = -1;
void plot(int x, int y, char c) {
    if (y < 0 || y >= MAXH || x < 0 || x >= MAXW) return;
    canvas[y][x] = c;
    if (y > max_y) max_y = y;
}

struct Point {
    int x, y;
    char c;
    Point(int _x = 0, int _y = 0, char _c = ' ') : x(_x), y(_y), c(_c) {}
};
void draw_house(int start_x, int L, int H, char dir) {
    vector<Point> points;
    char w_left = '@';
    char w_right = '&';
    if (dir == 'L' || dir == 'R') {
        swap(w_left, w_right);
    }
    for (int y = 1; y < H; y++) {
        points.emplace_back(0, y, w_left);
        points.emplace_back(L - 1, y, w_right);
    }
    for (int x = 0; x < L; x++) {
        points.emplace_back(x, 0, '#');
    }
    int roof_h = L / 2;
    for (int r = 0; r < roof_h; ++r) {
        int y = H + r;
        points.emplace_back(r, y, '/');
        points.emplace_back(L - 1 - r, y, '\\');
    }
    int total_h = H + roof_h;
    for (auto [x, y, c] : points) {
        int final_y = y;
        char final_c = c;
        if (dir == 'U' || dir == 'D') {
            final_y = total_h - 1 - y;
            if (c == '/')
                final_c = '\\';
            else if (c == '\\')
                final_c = '/';
        }
        plot(start_x + x, final_y, final_c);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < MAXH; i++) {
        for (int j = 0; j < MAXW; j++) {
            canvas[i][j] = ' ';
        }
    }
    string line, token;
    getline(cin, line);
    stringstream ss(line);
    int current_x = 0;
    while (ss >> token) {
        assert(token.find('x') != string::npos);
        int x_pos = token.find('x');
        int len = token.length();
        char dir = token[len - 1];
        int L = stoi(token.substr(0, x_pos));
        int H = stoi(token.substr(x_pos + 1, len - x_pos - 2));
        draw_house(current_x, L, H, dir);
        current_x += L;
    }
    int total_width = current_x;
    if (max_y == -1) return 0;
    for (int y = max_y; y >= 0; y--) {
        for (int x = 0; x < total_width; x++) {
            cout << canvas[y][x];
        }
        cout << "\n";
    }
    return 0;
}