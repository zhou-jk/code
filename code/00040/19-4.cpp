//AC
#include <bits/stdc++.h>

using namespace std;

const int N = 50, M = 3;
const bool s[M][M] = {{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};
char a[N][N + 1];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%s", a[i]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j] == '.') {
                for (int k = 0; k < M; ++k)
                    for (int p = 0; p < M; ++p)
                        if (i + k == n || j + p - 1 < 0 || j + p - 1 == n ||
                            (s[k][p] && a[i + k][j + p - 1] == '#')) {
                            puts("NO");
                            return 0;
                        } else if (s[k][p])
                            a[i + k][j + p - 1] = '#';
            }
    puts("YES");
    return 0;
}