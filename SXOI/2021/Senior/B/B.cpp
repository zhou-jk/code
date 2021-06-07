#include <cstdio>
#include <vector>

struct Segment_Tree_Max {
private:
    int n;
    struct Node {
        int l, r;
        std::pair<int, int> mx;
    };
    std::vector<Node>tree;
protected:
    std::pair<int, int> merge(const std::pair<int, int> &a, const std::pair<int, int> &b) const {
        std::pair<int, int>c = {std::max(a.first, b.first), -1};

        if (a.first != c.first)
            c.second = std::max(c.second, a.first);

        if (b.first != c.first)
            c.second = std::max(c.second, b.first);

        if (a.second != c.first)
            c.second = std::max(c.second, a.second);

        if (b.second != c.first)
            c.second = std::max(c.second, b.second);

        return c;
    }
    void push_up(int i) {
        tree[i].mx = merge(tree[i * 2].mx, tree[i * 2 + 1].mx);
        return;
    }
    void build(int i, int l, int r) {
        tree[i].l = l, tree[i].r = r;

        if (l == r) {
            tree[i].mx = {-1, -1};
            return;
        }

        int mid = (l + r) / 2;
        build(i * 2, l, mid);
        build(i * 2 + 1, mid + 1, r);
        push_up(i);
        return;
    };
    void modify(int i, int u, int v) {
        if (tree[i].l == tree[i].r) {
            if (v >= tree[i].mx.first)
                tree[i].mx.second = tree[i].mx.first, tree[i].mx.first = v;
            else if (v > tree[i].mx.second)
                tree[i].mx.second = v;

            return;
        }

        if (u <= tree[i * 2].r)
            modify(i * 2, u, v);
        else
            modify(i * 2 + 1, u, v);

        push_up(i);
        return;
    }
    std::pair<int, int> query(int i, int l, int r) {
        if (l > r)
            return {-1, -1};

        if (l <= tree[i].l && tree[i].r <= r)
            return tree[i].mx;

        std::pair<int, int>res = {-1, -1};

        if (l <= tree[i * 2].r)
            res = merge(res, query(i * 2, l, r));

        if (r >= tree[i * 2 + 1].l)
            res = merge(res, query(i * 2 + 1, l, r));

        return res;
    }
public:
    Segment_Tree_Max(const int &_n = 0) {
        n = _n;

        if (n == 0)
            return;

        tree.resize(n * 4 + 1);
        build(1, 1, n);
        return;
    }
    void init(const int &_n) {
        n = _n;
        tree.resize(n * 4 + 1);
        build(1, 1, n);
        return;
    }
    void modify(const int &u, const int &v) {
        return modify(1, u, v);
    }
    std::pair<int, int> query(const int &l, const int &r) {
        return query(1, l, r);
    }
};
struct Segment_Tree_Min {
private:
    int n;
    struct Node {
        int l, r;
        std::pair<int, int> mi;
    };
    std::vector<Node>tree;
protected:
    std::pair<int, int> merge(const std::pair<int, int> &a, const std::pair<int, int> &b) const {
        std::pair<int, int>c = {std::min(a.first, b.first), n};

        if (a.first != c.first)
            c.second = std::min(c.second, a.first);

        if (b.first != c.first)
            c.second = std::min(c.second, b.first);

        if (a.second != c.first)
            c.second = std::min(c.second, a.second);

        if (b.second != c.first)
            c.second = std::min(c.second, b.second);

        return c;
    }
    void push_up(int i) {
        tree[i].mi = merge(tree[i * 2].mi, tree[i * 2 + 1].mi);
        return;
    }
    void build(int i, int l, int r) {
        tree[i].l = l, tree[i].r = r;

        if (l == r) {
            tree[i].mi = {n, n};
            return;
        }

        int mid = (l + r) / 2;
        build(i * 2, l, mid);
        build(i * 2 + 1, mid + 1, r);
        push_up(i);
        return;
    };
    void modify(int i, int u, int v) {
        if (tree[i].l == tree[i].r) {
            if (v <= tree[i].mi.first)
                tree[i].mi.second = tree[i].mi.first, tree[i].mi.first = v;
            else if (v < tree[i].mi.second)
                tree[i].mi.second = v;

            return;
        }

        if (u <= tree[i * 2].r)
            modify(i * 2, u, v);
        else
            modify(i * 2 + 1, u, v);

        push_up(i);
        return;
    }
    std::pair<int, int> query(int i, int l, int r) {
        if (l > r)
            return {n, n};

        if (l <= tree[i].l && tree[i].r <= r)
            return tree[i].mi;

        std::pair<int, int>res = {n, n};

        if (l <= tree[i * 2].r)
            res = merge(res, query(i * 2, l, r));

        if (r >= tree[i * 2 + 1].l)
            res = merge(res, query(i * 2 + 1, l, r));

        return res;
    }
public:
    Segment_Tree_Min(const int &_n = 0) {
        n = _n;

        if (n == 0)
            return;

        tree.resize(n * 4 + 1);
        build(1, 1, n);
        return;
    }
    void init(const int &_n) {
        n = _n;
        tree.resize(n * 4 + 1);
        build(1, 1, n);
        return;
    }
    void modify(const int &u, const int &v) {
        return modify(1, u, v);
    }
    std::pair<int, int> query(const int &l, const int &r) {
        return query(1, l, r);
    }
};
int main() {
    int n;
    scanf("%d", &n);
    std::vector<int>a(n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    Segment_Tree_Max T1(n);
    std::vector<int>pre(n), prel(n);

    for (int i = 0; i < n; i++) {
        auto [l, L] = T1.query(a[i] + 1, n);
        pre[i] = l, prel[i] = L;
        T1.modify(a[i], i);
    }

    Segment_Tree_Min T2(n);
    std::vector<int>nxt(n), nxtr(n);

    for (int i = n - 1; i >= 0; i--) {
        auto [r, R] = T2.query(a[i] + 1, n);
        nxt[i] = r, nxtr[i] = R;
        T2.modify(a[i], i);
    }

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int l = pre[i], r = nxt[i];

        if (l >= 0)
            ans += (long long)a[i] * (l - prel[i]) * (r - i);

        if (r < n)
            ans += (long long)a[i] * (i - l) * (nxtr[i] - r);
    }

    printf("%lld", ans);
    return 0;
}