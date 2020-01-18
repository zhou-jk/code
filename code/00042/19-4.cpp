//WA
#include <bits/stdc++.h>

using namespace std;

const int N = 100000, LEN = 250;
char ss[10], s[N + 1], w[3][LEN + 1];
int cnt[3];
bool vis[N];

int main() {
    int n, q;
    scanf("%d%d%s", &n, &q, s);
    for (int i = 0; i < q; ++i) {
        char op;
        int k;
        gets(ss);
        scanf("%c %d", &op, &k);
        --k;
        if (op == '+') {
            char ch;
            scanf(" %c", &ch);
            w[k][cnt[k]++] = ch;
        } else
            --cnt[k];
        memset(vis, 0, sizeof vis);
        bool flag = false;
        for (int j = 0; j < 3; ++j) {
            int p = n - 1;
            for (int k = cnt[j] - 1; ~k; --k) {
                while (~p && (vis[p] || s[p] != w[j][k])) --p;
                if (p == -1) {
                    flag = true;
                    break;
                }
                vis[p] = true;
            }
            if (flag) break;
        }
        if (flag)
            puts("NO");
        else
            puts("YES");
    }
    return 0;
}
