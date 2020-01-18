// AC
#include <cstdio>
#include <cstring>

const int N = 30000, LEN = 300000, N_KIND = 26;
const char FIRST_KIND = 'a';
char tmp[LEN + 1];
char *str[N];
int trie[LEN + 1][N_KIND], ind[N_KIND], cnt;
bool end[LEN + 1], cmp[N_KIND][N_KIND], flag[N], vis[N_KIND];

void insert(const char str[]) {
    int k = 0;
    for (int i = 0; str[i]; ++i) {
        int index = str[i] - FIRST_KIND;
        if (!trie[k][index]) trie[k][index] = ++cnt;
        k = trie[k][index];
    }
    end[k] = true;
}

void topo(int k) {
    vis[k] = true;
    for (int i = 0; i < N_KIND; ++i)
        if (cmp[k][i]) {
            --ind[i];
            if (!ind[i]) topo(i);
        }
}

bool check(const char str[]) {
    memset(cmp, 0, sizeof cmp);
    memset(ind, 0, sizeof ind);
    memset(vis, 0, sizeof vis);
    int k = 0;
    for (int i = 0; str[i]; ++i) {
        if (end[k]) return false;
        int index = str[i] - FIRST_KIND;
        for (int j = 0; j < N_KIND; ++j)
            if (trie[k][j] && j != index) {
                if (cmp[j][index]) return false;
                if (!cmp[index][j]) {
                    cmp[index][j] = true;
                    ++ind[j];
                }
            }
        k = trie[k][index];
    }
    for (int i = 0; i < N_KIND; ++i)
        if (!ind[i] && !vis[i]) topo(i);
    for (int i = 0; i < N_KIND; ++i)
        if (!vis[i]) return false;
    return true;
}

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", tmp);
        int len = strlen(tmp);
        str[i] = new char[len + 1];
        memcpy(str[i], tmp, len + 1);
        insert(tmp);
    }
    for (int i = 0; i < n; ++i) ans += (flag[i] = check(str[i]));
    printf("%d\n", ans);
    for (int i = 0; i < n; ++i)
        if (flag[i]) puts(str[i]);
    return 0;
}
