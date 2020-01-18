#include <bits/stdc++.h>
using namespace std;
inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
const int L = 100000;
char ppp[L];
char *p1, *p2;
inline char ckakioi() {
    if (p1 == p2) p2 = (p1 = ppp) + fread(ppp, 1, L, stdin);
    return *p1++;
}
//#define getchar ckakioi
inline int readc() {
    char ch = getchar();
    while (ch != '0' && ch != '1') {
        ch = getchar();
    }
    return (int)ch - '0';
}
int n;

int huan[30], cnt;
bool visit[5010];
bool can[5010][5010];
bool laa = false;
int deep[5001];
bool dfs(int x, int ff) {
    visit[x] = 1;
    bool flag = false;
    for (register int i = 1; i <= n; ++i) {
        if (can[x][i] && can[i][ff]) {
            cout << ff << " " << x << " " << i;
            return 1;
        } else {
            if (can[x][i]) {
                if (!visit[i]) {
                    if (dfs(i, x)) {
                        return 1;
                    }
                }
            }
        }
    }
    return false;
}
int main() {
    //  freopen("cycle.in","r",stdin);
    //  freopen("cycle.out","w",stdout);
    scanf("%d", &n);
    for (register int i = 1; i <= n; ++i) {
        for (register int j = 1; j <= n; ++j) {
            //          puts("QWQ");
            int x = readc();
            if (x == 1) {
                can[i][j] = 1;
            }
        }
    }

    for (register int i = 1; i <= n; ++i) {
        if (!visit[i])
            if (dfs(i, 0)) {
                return 0;
            }
    }
    puts("-1");
    // ckakioi
}