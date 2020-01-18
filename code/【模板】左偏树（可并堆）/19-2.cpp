// AC
#include <algorithm>
#include <cstdio>

using std::swap;

const int N = 100000 + 1;
struct Node {
    Node() : num(0), fa(0), lc(0), rc(0), dis(0){};
    int num, fa, lc, rc, dis;
} node[N];

int getFa(const int k) {
    return k == node[k].fa ? k : node[k].fa = getFa(node[k].fa);
}

int merge(int x, int y) {
    if (!x || !y) return x + y;
    if (node[x].num == node[y].num ? y < x : node[y].num < node[x].num)
        swap(x, y);
    node[x].rc = merge(node[x].rc, y);
    node[node[x].rc].fa = x;
    if (node[node[x].lc].dis < node[node[x].rc].dis)
        swap(node[x].lc, node[x].rc);
    node[x].dis = node[node[x].rc].dis + 1;
    return x;
}

int pop(const int x) {
    int ret = node[x].num;
    node[x].num = -1;
    node[node[x].lc].fa = node[x].lc;
    node[node[x].rc].fa = node[x].rc;
    node[x].fa = merge(node[x].lc, node[x].rc);
    return ret;
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    node[0].dis = -1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &node[i].num);
        node[i].fa = i;
    }
    for (int i = 0; i < q; ++i) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int x, y;
            scanf("%d%d", &x, &y);
            if (node[x].num == -1 || node[y].num == -1) continue;
            x = getFa(x);
            y = getFa(y);
            if (x != y) node[x].fa = node[y].fa = merge(x, y);
        } else {
            int x;
            scanf("%d", &x);
            if (node[x].num == -1) {
                puts("-1");
                continue;
            }
            x = getFa(x);
            printf("%d\n", pop(x));
        }
    }
    return 0;
}