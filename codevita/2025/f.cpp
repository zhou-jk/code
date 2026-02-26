#include <bits/stdc++.h>
using namespace std;
constexpr int N = 16;
enum Face { BOTTOM = 0, BACK = 1, TOP = 2, FRONT = 3, LEFT = 4, RIGHT = 5 };
enum InstrType { TURN_LEFT, TURN_RIGHT, ROTATE_FRONT, ROTATE_BACK, ROTATE_LEFT, ROTATE_RIGHT, SLICE_MOVE };

struct Instruction {
    InstrType type;
    int side;
    int idx;
    bool is_row;
    bool cw;
};

class Cube {
   private:
    char data[6][N][N];
    char original[6][N][N];
    int size;
    void rotate_face_cw(char f[N][N]) {
        char temp[N][N];
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++) temp[j][size - 1 - i] = f[i][j];
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++) f[i][j] = temp[i][j];
    }
    void rotate_face_ccw(char f[N][N]) {
        char temp[N][N];
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++) temp[size - 1 - j][i] = f[i][j];
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++) f[i][j] = temp[i][j];
    }
    void copy_from(const char src[6][N][N]) {
        for (int f = 0; f < 6; f++)
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++) data[f][i][j] = src[f][i][j];
    }
    void copy_to(char dest[6][N][N]) const {
        for (int f = 0; f < 6; f++)
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++) dest[f][i][j] = data[f][i][j];
    }

   public:
    Cube(int n) : size(n) {}
    void read_faces() {
        for (int f = 0; f < 6; f++)
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++) {
                    string s;
                    cin >> s;
                    data[f][i][j] = original[f][i][j] = s[0];
                }
    }
    void reset_to_original() { copy_from(original); }
    void turn_left() {
        char cycle[6][N][N];
        copy_to(cycle);
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++) {
                data[FRONT][i][j] = cycle[RIGHT][i][j];
                data[RIGHT][i][j] = cycle[BACK][i][j];
                data[BACK][i][j] = cycle[LEFT][i][j];
                data[LEFT][i][j] = cycle[FRONT][i][j];
            }
        rotate_face_cw(data[TOP]);
        rotate_face_ccw(data[BOTTOM]);
    }
    void turn_right() {
        char cycle[6][N][N];
        copy_to(cycle);
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++) {
                data[FRONT][i][j] = cycle[LEFT][i][j];
                data[LEFT][i][j] = cycle[BACK][i][j];
                data[BACK][i][j] = cycle[RIGHT][i][j];
                data[RIGHT][i][j] = cycle[FRONT][i][j];
            }
        rotate_face_ccw(data[TOP]);
        rotate_face_cw(data[BOTTOM]);
    }
    void rotate_front() {
        char cycle[6][N][N];
        copy_to(cycle);
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++) {
                data[FRONT][i][j] = cycle[TOP][i][j];
                data[TOP][i][j] = cycle[BACK][i][j];
                data[BACK][i][j] = cycle[BOTTOM][i][j];
                data[BOTTOM][i][j] = cycle[FRONT][i][j];
            }
        rotate_face_cw(data[LEFT]);
        rotate_face_ccw(data[RIGHT]);
    }
    void rotate_back() {
        char cycle[6][N][N];
        copy_to(cycle);
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++) {
                data[FRONT][i][j] = cycle[BOTTOM][i][j];
                data[BOTTOM][i][j] = cycle[BACK][i][j];
                data[BACK][i][j] = cycle[TOP][i][j];
                data[TOP][i][j] = cycle[FRONT][i][j];
            }
        rotate_face_ccw(data[LEFT]);
        rotate_face_cw(data[RIGHT]);
    }
    void rotate_left() {
        char cycle[6][N][N];
        copy_to(cycle);
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++) {
                data[TOP][i][j] = cycle[RIGHT][i][j];
                data[RIGHT][i][j] = cycle[BOTTOM][i][j];
                data[BOTTOM][i][j] = cycle[LEFT][i][j];
                data[LEFT][i][j] = cycle[TOP][i][j];
            }
        rotate_face_ccw(data[FRONT]);
        rotate_face_cw(data[BACK]);
    }
    void rotate_right() {
        char cycle[6][N][N];
        copy_to(cycle);
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++) {
                data[TOP][i][j] = cycle[LEFT][i][j];
                data[LEFT][i][j] = cycle[BOTTOM][i][j];
                data[BOTTOM][i][j] = cycle[RIGHT][i][j];
                data[RIGHT][i][j] = cycle[TOP][i][j];
            }
        rotate_face_cw(data[FRONT]);
        rotate_face_ccw(data[BACK]);
    }

   private:
    void band_row_front(int r, bool to_right) {
        if (to_right) {
            char tmp[N];
            for (int j = 0; j < size; j++) tmp[j] = data[FRONT][r][j];
            for (int j = 0; j < size; j++) data[FRONT][r][j] = data[LEFT][r][j];
            for (int j = 0; j < size; j++) data[LEFT][r][j] = data[BACK][r][size - 1 - j];
            for (int j = 0; j < size; j++) data[BACK][r][j] = data[RIGHT][r][size - 1 - j];
            for (int j = 0; j < size; j++) data[RIGHT][r][j] = tmp[j];
        } else {
            char tmp[N];
            for (int j = 0; j < size; j++) tmp[j] = data[FRONT][r][j];
            for (int j = 0; j < size; j++) data[FRONT][r][j] = data[RIGHT][r][j];
            for (int j = 0; j < size; j++) data[RIGHT][r][j] = data[BACK][r][size - 1 - j];
            for (int j = 0; j < size; j++) data[BACK][r][j] = data[LEFT][r][size - 1 - j];
            for (int j = 0; j < size; j++) data[LEFT][r][j] = tmp[j];
        }
    }
    void band_col_front(int c, bool to_down) {
        if (to_down) {
            char T[N], F[N], Ba[N], Bk[N];
            for (int i = 0; i < size; i++) {
                T[i] = data[TOP][i][c];
                F[i] = data[FRONT][i][c];
                Ba[i] = data[BOTTOM][i][c];
                Bk[i] = data[BACK][i][c];
            }
            for (int i = 0; i < size; i++) data[TOP][i][c] = Bk[size - 1 - i];
            for (int i = 0; i < size; i++) data[FRONT][i][c] = T[i];
            for (int i = 0; i < size; i++) data[BOTTOM][i][c] = F[i];
            for (int i = 0; i < size; i++) data[BACK][i][c] = Ba[size - 1 - i];
        } else {
            char T[N], F[N], Ba[N], Bk[N];
            for (int i = 0; i < size; i++) {
                T[i] = data[TOP][i][c];
                F[i] = data[FRONT][i][c];
                Ba[i] = data[BOTTOM][i][c];
                Bk[i] = data[BACK][i][c];
            }
            for (int i = 0; i < size; i++) data[TOP][i][c] = F[i];
            for (int i = 0; i < size; i++) data[FRONT][i][c] = Ba[i];
            for (int i = 0; i < size; i++) data[BOTTOM][i][c] = Bk[size - 1 - i];
            for (int i = 0; i < size; i++) data[BACK][i][c] = T[size - 1 - i];
        }
    }

    void do_turns(const vector<int>& ops) {
        for (int op : ops) {
            if (op == 1)
                turn_left();
            else if (op == 2)
                turn_right();
            else if (op == 3)
                rotate_front();
            else if (op == 4)
                rotate_back();
            else if (op == 5)
                rotate_left();
            else if (op == 6)
                rotate_right();
        }
    }

   public:
    void slice_move(int side, int idx, bool is_row, bool cw) {
        vector<int> go, back;
        if (side == FRONT) {
        } else if (side == BACK) {
            go = {1, 1};
            back = {2, 2};
        } else if (side == LEFT) {
            go = {2};
            back = {1};
        } else if (side == RIGHT) {
            go = {1};
            back = {2};
        } else if (side == TOP) {
            go = {3};
            back = {4};
        } else if (side == BOTTOM) {
            go = {4};
            back = {3};
        }
        auto do_turns = [&](const vector<int>& ops) {
            for (int op : ops) {
                if (op == 1)
                    turn_left();
                else if (op == 2)
                    turn_right();
                else if (op == 3)
                    rotate_front();
                else if (op == 4)
                    rotate_back();
                else if (op == 5)
                    rotate_left();
                else if (op == 6)
                    rotate_right();
            }
        };

        do_turns(go);
        if (is_row)
            band_row_front(idx, cw);
        else
            band_col_front(idx, cw);
        reverse(back.begin(), back.end());
        do_turns(back);
    }
    void apply(const vector<Instruction>& instrs, int skip = -1) {
        reset_to_original();
        for (int k = 0; k < (int)instrs.size(); k++) {
            if (k == skip) continue;
            const auto& ins = instrs[k];
            switch (ins.type) {
                case TURN_LEFT:
                    turn_left();
                    break;
                case TURN_RIGHT:
                    turn_right();
                    break;
                case ROTATE_FRONT:
                    rotate_front();
                    break;
                case ROTATE_BACK:
                    rotate_back();
                    break;
                case ROTATE_LEFT:
                    rotate_left();
                    break;
                case ROTATE_RIGHT:
                    rotate_right();
                    break;
                case SLICE_MOVE:
                    slice_move(ins.side, ins.idx, ins.is_row, ins.cw);
                    break;
            }
        }
    }
    bool has_uniform_face() const {
        for (int f = 0; f < 6; f++) {
            char first = data[f][0][0];
            bool ok = true;
            for (int i = 0; i < size && ok; i++)
                for (int j = 0; j < size; j++)
                    if (data[f][i][j] != first) {
                        ok = false;
                        break;
                    }
            if (ok) return true;
        }
        return false;
    }
    bool has_almost_uniform_face() const {
        for (int f = 0; f < 6; f++) {
            unordered_map<char, int> cnt;
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++) cnt[data[f][i][j]]++;
            int mx = 0;
            for (auto& p : cnt) mx = max(mx, p.second);
            if (size * size - mx <= 1) return true;
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    Cube cube(n);
    cube.read_faces();
    vector<Instruction> instrs(k);
    for (int i = 0; i < k; i++) {
        string w1;
        cin >> w1;
        Instruction& ins = instrs[i];
        if (w1 == "turn") {
            string dir;
            cin >> dir;
            ins.type = (dir == "left") ? TURN_LEFT : TURN_RIGHT;
        } else if (w1 == "rotate") {
            string s;
            cin >> s;
            if (s == "front")
                ins.type = ROTATE_FRONT;
            else if (s == "back")
                ins.type = ROTATE_BACK;
            else if (s == "left")
                ins.type = ROTATE_LEFT;
            else if (s == "right")
                ins.type = ROTATE_RIGHT;
        } else {
            ins.type = SLICE_MOVE;
            if (w1 == "base")
                ins.side = BOTTOM;
            else if (w1 == "back")
                ins.side = BACK;
            else if (w1 == "top")
                ins.side = TOP;
            else if (w1 == "front")
                ins.side = FRONT;
            else if (w1 == "left")
                ins.side = LEFT;
            else if (w1 == "right")
                ins.side = RIGHT;
            string num_str, dir;
            cin >> num_str >> dir;
            ins.idx = stoi(num_str) - 1;
            ins.is_row = (dir == "left" || dir == "right");
            ins.cw = (dir == "right" || dir == "down");
        }
    }

    auto instr_to_string = [&](const Instruction& ins) -> string {
        if (ins.type == TURN_LEFT || ins.type == TURN_RIGHT)
            return string("turn ") + (ins.type == TURN_LEFT ? "left" : "right");
        if (ins.type >= ROTATE_FRONT && ins.type <= ROTATE_RIGHT) {
            static string s[] = {"front", "back", "left", "right"};
            return string("rotate ") + s[ins.type - ROTATE_FRONT];
        }
        static string sides[] = {"base", "back", "top", "front", "left", "right"};
        string dir = ins.is_row ? (ins.cw ? "right" : "left") : (ins.cw ? "down" : "up");
        return sides[ins.side] + " " + to_string(ins.idx + 1) + " " + dir;
    };
    for (int skip = 0; skip < k; skip++) {
        cube.apply(instrs, skip);
        if (cube.has_uniform_face()) {
            cout << instr_to_string(instrs[skip]);
            return 0;
        }
    }
    for (int skip = 0; skip < k; skip++) {
        cube.apply(instrs, skip);
        if (cube.has_almost_uniform_face()) {
            cout << "Faulty\n" << instr_to_string(instrs[skip]);
            return 0;
        }
    }
    cout << "Not Possible";
    return 0;
}
