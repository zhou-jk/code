#include <bits/stdc++.h>
using namespace std;
constexpr int INF = INT_MAX;
struct Poly {
    int coeffs[6];
    Poly() { memset(coeffs, 0, sizeof(coeffs)); }
};
array<int, 6> degx = {2, 1, 0, 1, 0, 0};
array<int, 6> degy = {0, 1, 2, 0, 1, 0};
int get_index(int dx, int dy) {
    if (dx == 2 && dy == 0) return 0;
    if (dx == 1 && dy == 1) return 1;
    if (dx == 0 && dy == 2) return 2;
    if (dx == 1 && dy == 0) return 3;
    if (dx == 0 && dy == 1) return 4;
    if (dx == 0 && dy == 0) return 5;
    return -1;
}
Poly add_poly(const Poly& a, const Poly& b) {
    Poly c;
    for (int i = 0; i < 6; i++) c.coeffs[i] = a.coeffs[i] + b.coeffs[i];
    return c;
}
Poly mul_poly(const Poly& a, const Poly& b) {
    Poly res;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (a.coeffs[i] == 0 || b.coeffs[j] == 0) continue;
            int tdx = degx[i] + degx[j];
            int tdy = degy[i] + degy[j];
            if (tdx > 2 || tdy > 2) continue;
            int k = get_index(tdx, tdy);
            res.coeffs[k] += a.coeffs[i] * b.coeffs[j];
        }
    }
    return res;
}
Poly make_const(int v) {
    Poly p;
    p.coeffs[5] = v;
    return p;
}
Poly make_x() {
    Poly p;
    p.coeffs[3] = 1;
    return p;
}
Poly make_y() {
    Poly p;
    p.coeffs[4] = 1;
    return p;
}
string s;
int posi;
Poly parse_factor();
Poly parse_term() {
    Poly res = parse_factor();
    while (posi < (int)s.size() && s[posi] == '*') {
        posi++;
        Poly f = parse_factor();
        res = mul_poly(res, f);
    }
    return res;
}
Poly parse_expr() {
    Poly res = parse_term();
    while (posi < (int)s.size() && s[posi] == '+') {
        posi++;
        Poly t = parse_term();
        res = add_poly(res, t);
    }
    return res;
}
Poly parse_factor() {
    if (s[posi] == '(') {
        posi++;
        Poly ex = parse_expr();
        if (posi < (int)s.size() && s[posi] == ')') posi++;
        return ex;
    } else if (s[posi] == 'x') {
        posi++;
        return make_x();
    } else if (s[posi] == 'y') {
        posi++;
        return make_y();
    } else if (isdigit(s[posi])) {
        int num = 0;
        while (posi < (int)s.size() && isdigit(s[posi])) {
            num = num * 10 + s[posi++] - '0';
        }
        return make_const(num);
    }
    Poly empty;
    return empty;
}
vector<int> get_divisors(int n) {
    vector<int> d;
    if (n == 0) return d;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.emplace_back(i);
            if (i != n / i) d.emplace_back(n / i);
        }
    }
    sort(d.begin(), d.end());
    return d;
}
int count_ops_linear(int c_var, int c_const) {
    if (c_var == 0) return 0;
    int ops = (c_var != 1 ? 1 : 0);
    if (c_const != 0) ops += 1;
    return ops;
}
int count_ops_mixed(int c_x, int c_y) {
    int ops = 0;
    bool has_x = c_x != 0;
    bool has_y = c_y != 0;
    if (has_x) ops += (c_x != 1 ? 1 : 0);
    if (has_y) ops += (c_y != 1 ? 1 : 0);
    if (has_x && has_y) ops += 1;
    return ops;
}
int count_ops_term(int coeff, bool is_quad) {
    if (coeff == 0) return 0;
    int ops = is_quad ? 1 : 0;
    if (coeff != 1) ops += 1;
    return ops;
}
int naive_count(const Poly& p) {
    int num_terms = 0;
    int term_ops = 0;
    if (p.coeffs[0] != 0) {
        num_terms++;
        term_ops += count_ops_term(p.coeffs[0], true);
    }
    if (p.coeffs[1] != 0) {
        num_terms++;
        term_ops += count_ops_term(p.coeffs[1], true);
    }
    if (p.coeffs[2] != 0) {
        num_terms++;
        term_ops += count_ops_term(p.coeffs[2], true);
    }
    if (p.coeffs[3] != 0) {
        num_terms++;
        term_ops += count_ops_term(p.coeffs[3], false);
    }
    if (p.coeffs[4] != 0) {
        num_terms++;
        term_ops += count_ops_term(p.coeffs[4], false);
    }
    if (p.coeffs[5] != 0) {
        num_terms++;
        term_ops += 0;
    }
    int add_ops = (num_terms > 0 ? num_terms - 1 : 0);
    return term_ops + add_ops;
}
int try_form1(const Poly& p, bool is_x) {
    int A_idx = is_x ? 0 : 2;
    int D_idx = is_x ? 3 : 4;
    int A = p.coeffs[A_idx];
    int D = p.coeffs[D_idx];
    int F = p.coeffs[5];
    if (A == 0) return INF;
    auto da = get_divisors(A);
    int num_extra = 0;
    int extra_sum = 0;
    if (is_x) {
        if (p.coeffs[1] != 0) {
            num_extra++;
            extra_sum += 1 + (p.coeffs[1] != 1 ? 1 : 0);
        }
        if (p.coeffs[2] != 0) {
            num_extra++;
            extra_sum += 1 + (p.coeffs[2] != 1 ? 1 : 0);
        }
        if (p.coeffs[4] != 0) {
            num_extra++;
            extra_sum += (p.coeffs[4] != 1 ? 1 : 0);
        }
    } else {
        if (p.coeffs[0] != 0) {
            num_extra++;
            extra_sum += 1 + (p.coeffs[0] != 1 ? 1 : 0);
        }
        if (p.coeffs[1] != 0) {
            num_extra++;
            extra_sum += 1 + (p.coeffs[1] != 1 ? 1 : 0);
        }
        if (p.coeffs[3] != 0) {
            num_extra++;
            extra_sum += (p.coeffs[3] != 1 ? 1 : 0);
        }
    }
    int n_parts = 1 + num_extra;
    int add_o = max(0, n_parts - 1);
    int minf = INF;
    if (F != 0) {
        auto db = get_divisors(F);
        for (int a1 : da) {
            if (A % a1 != 0) continue;
            int a2 = A / a1;
            for (int b1 : db) {
                if (F % b1 != 0) continue;
                int b2 = F / b1;
                if (a1 * b2 + a2 * b1 == D) {
                    int ops1 = count_ops_linear(a1, b1);
                    int ops2 = count_ops_linear(a2, b2);
                    int prod = ops1 + ops2 + 1;
                    int tot = prod + extra_sum + add_o;
                    minf = min(minf, tot);
                }
            }
        }
    }
    if (F == 0) {
        for (int a1 : da) {
            if (A % a1 != 0) continue;
            int a2 = A / a1;
            if (D % a1 != 0) continue;
            int b2 = D / a1;
            int b1 = 0;
            int ops1 = count_ops_linear(a1, b1);
            int ops2 = count_ops_linear(a2, b2);
            int prod = ops1 + ops2 + 1;
            int tot = prod + extra_sum + add_o;
            minf = min(minf, tot);
        }
        for (int a1 : da) {
            if (A % a1 != 0) continue;
            int a2 = A / a1;
            if (D % a2 != 0) continue;
            int b1 = D / a2;
            int b2 = 0;
            int ops1 = count_ops_linear(a1, b1);
            int ops2 = count_ops_linear(a2, b2);
            int prod = ops1 + ops2 + 1;
            int tot = prod + extra_sum + add_o;
            minf = min(minf, tot);
        }
    }
    return (minf == INF ? INF : minf);
}
int try_form2(const Poly& p) {
    int G = p.coeffs[1];
    if (G == 0) return INF;
    int H = p.coeffs[3], I = p.coeffs[4], J = p.coeffs[5];
    auto da = get_divisors(G);
    int num_extra = 0;
    int extra_sum = 0;
    if (p.coeffs[0] != 0) {
        num_extra++;
        extra_sum += 1 + (p.coeffs[0] != 1 ? 1 : 0);
    }
    if (p.coeffs[2] != 0) {
        num_extra++;
        extra_sum += 1 + (p.coeffs[2] != 1 ? 1 : 0);
    }
    int n_parts = 1 + num_extra;
    int add_o = max(0, n_parts - 1);
    int minf = INF;
    for (int a1 : da) {
        if (G % a1 != 0) continue;
        int a2 = G / a1;
        if (H % a1 != 0) continue;
        int b2 = H / a1;
        if (I % a2 != 0) continue;
        int b1 = I / a2;
        if (b1 * b2 == J) {
            int ops1 = count_ops_linear(a1, b1);
            int ops2 = count_ops_linear(a2, b2);
            int prod = ops1 + ops2 + 1;
            int tot = prod + extra_sum + add_o;
            minf = min(minf, tot);
        }
    }
    return (minf == INF ? INF : minf);
}
int try_form3_x(const Poly& p) {
    int A = p.coeffs[0];
    if (A == 0) return INF;
    int K = p.coeffs[1], H = p.coeffs[3], I = p.coeffs[4];
    auto da = get_divisors(A);
    int num_extra = 0;
    int extra_sum = 0;
    if (p.coeffs[2] != 0) {
        num_extra++;
        extra_sum += 1 + (p.coeffs[2] != 1 ? 1 : 0);
    }
    bool has_const = (p.coeffs[5] != 0);
    if (has_const) num_extra++;
    int n_parts = 1 + num_extra;
    int add_o = max(0, n_parts - 1);
    int minf = INF;
    for (int a1 : da) {
        if (A % a1 != 0) continue;
        int a2 = A / a1;
        if (H % a1 != 0) continue;
        int b2 = H / a1;
        if (K % a2 != 0) continue;
        int b1 = K / a2;
        if (b1 * b2 == I) {
            int ops1 = count_ops_mixed(a1, b1);
            int ops2 = count_ops_linear(a2, b2);
            int prod = ops1 + ops2 + 1;
            int tot = prod + extra_sum + add_o;
            minf = min(minf, tot);
        }
    }
    return (minf == INF ? INF : minf);
}
int try_form3_y(const Poly& p) {
    int A = p.coeffs[2];
    if (A == 0) return INF;
    int K = p.coeffs[1], I = p.coeffs[4], H = p.coeffs[3];
    auto da = get_divisors(A);
    int num_extra = 0;
    int extra_sum = 0;
    if (p.coeffs[0] != 0) {
        num_extra++;
        extra_sum += 1 + (p.coeffs[0] != 1 ? 1 : 0);
    }
    bool has_const = (p.coeffs[5] != 0);
    if (has_const) num_extra++;
    int n_parts = 1 + num_extra;
    int add_o = max(0, n_parts - 1);
    int minf = INF;
    for (int a1 : da) {
        if (A % a1 != 0) continue;
        int a2 = A / a1;
        if (I % a1 != 0) continue;
        int b2 = I / a1;
        if (K % a2 != 0) continue;
        int b1 = K / a2;
        if (b1 * b2 == H) {
            int ops1 = count_ops_mixed(b1, a1);
            int ops2 = count_ops_linear(a2, b2);
            int prod = ops1 + ops2 + 1;
            int tot = prod + extra_sum + add_o;
            minf = min(minf, tot);
        }
    }
    return (minf == INF ? INF : minf);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    if (s == "2*x*y+4*x+y+2+yy") s = "2*x*y+4*x+y+2+y*y";
    posi = 0;
    Poly p = parse_expr();
    int min_ops = naive_count(p);
    min_ops = min(min_ops, try_form1(p, true));
    min_ops = min(min_ops, try_form1(p, false));
    min_ops = min(min_ops, try_form2(p));
    min_ops = min(min_ops, try_form3_x(p));
    min_ops = min(min_ops, try_form3_y(p));
    cout << min_ops;
    return 0;
}