// AC
#include <cstdio>

#define mid ((l[k] + r[k]) >> 1)
#define lc (k << 1)
#define rc ((k << 1) | 1)

const int N = 100000;
int l[N << 2], r[N << 2];
long long node[N << 2], tag1[N << 2], tag2[N << 2], p;

void modify(int k, long long val, int op) {
    val %= p;
    if (op == 2) {
        node[k] = (node[k] + val * (r[k] - l[k] + 1) % p) % p;
        tag1[k] = (tag1[k] + val) % p;
    } else {
        node[k] = node[k] * val % p;
        tag1[k] = tag1[k] * val % p;
        tag2[k] = tag2[k] * val % p;
    }
}

void push_up(int k) { node[k] = (node[lc] + node[rc]) % p; }

void push_down(int k) {
    modify(lc, tag2[k], 1);
    modify(rc, tag2[k], 1);
    modify(lc, tag1[k], 2);
    modify(rc, tag1[k], 2);
    tag1[k] = 0;
    tag2[k] = 1;
}

void build(int k, int _l, int _r) {
    l[k] = _l;
    r[k] = _r;
    tag2[k] = 1;
    if (l[k] == r[k]) {
        scanf("%lld", node + k);
        node[k] %= p;
        return;
    }
    build(lc, l[k], mid);
    build(rc, mid + 1, r[k]);
    push_up(k);
}

void update(int k, int l_, int r_, long long val, int op) {
    if (l_ <= l[k] && r[k] <= r_) {
        modify(k, val, op);
        return;
    }
    push_down(k);
    if (l_ <= mid) update(lc, l_, r_, val, op);
    if (r_ > mid) update(rc, l_, r_, val, op);
    push_up(k);
}

long long query(int k, int l_, int r_) {
    // printf("#%d %d %d\n", l[k], r[k], node[k]);
    if (l_ <= l[k] && r[k] <= r_) return node[k];
    long long ret = 0;
    push_down(k);
    if (l_ <= mid) ret = (ret + query(lc, l_, r_)) % p;
    if (r_ > mid) ret = (ret + query(rc, l_, r_)) % p;
    return ret;
}

int main() {
    int n, m;
    scanf("%d%d%lld", &n, &m, &p);
    build(1, 1, n);
    while (m--) {
        int op, l, r;
        scanf("%d%d%d", &op, &l, &r);
        if (op < 3) {
            long long val;
            scanf("%lld", &val);
            update(1, l, r, val, op);
        } else
            printf("%lld\n", query(1, l, r));
    }
    return 0;
}