#include <bits/stdc++.h>
using namespace std;
constexpr long long INF = 1e18;
int main() {
    string S;
    cin >> S;
    int M = S.length();
    int N;
    cin >> N;
    vector<string> pieces(N);
    for (int i = 0; i < N; i++) {
        cin >> pieces[i];
    }
    vector<int> costs(N);
    for (int i = 0; i < N; i++) {
        cin >> costs[i];
    }
    vector<vector<int>> pre(M + 1, vector<int>(26, 0));
    for (int i = 1; i <= M; i++) {
        int c = S[i - 1] - 'a';
        for (int j = 0; j < 26; j++) {
            pre[i][j] = pre[i - 1][j];
        }
        pre[i][c]++;
    }
    vector<vector<int>> num(N, vector<int>(26, 0));
    for (int k = 0; k < N; k++) {
        for (char ch : pieces[k]) {
            num[k][ch - 'a']++;
        }
    }
    vector<long long> f(M + 1, INF);
    f[0] = 0;
    for (int i = 1; i <= M; i++) {
        for (int k = 0; k < N; k++) {
            int lmax = 0;
            for (int l = 1; l <= min(20, i); l++) {
                int j = i - l;
                bool ok = true;
                for (int c = 0; c < 26; c++) {
                    int cnt = pre[i][c] - pre[j][c];
                    if (cnt > num[k][c]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    lmax = l;
                }
            }
            if (lmax == 0) continue;
            long long min_prev = INF;
            for (int l = 1; l <= lmax; l++) {
                int j = i - l;
                min_prev = min(min_prev, f[j]);
            }
            if (min_prev < INF) {
                f[i] = min(f[i], min_prev + costs[k]);
            }
        }
    }
    vector<long long> g(M + 1, INF);
    g[0] = 0;
    for (int i = 1; i <= M; i++) {
        for (int k = 0; k < N; k++) {
            string P = pieces[k];
            int plen = P.length();
            int lmax = 0;
            for (int l = 1; l <= min(plen, i); l++) {
                int tptr = 0;
                int start_idx = i - l;
                for (char ch : P) {
                    if (tptr < l && ch == S[start_idx + tptr]) {
                        tptr++;
                    }
                    if (tptr == l) break;
                }
                if (tptr == l) {
                    lmax = l;
                }
            }
            if (lmax == 0) continue;
            long long min_prev = INF;
            for (int l = 1; l <= lmax; l++) {
                int j = i - l;
                min_prev = min(min_prev, g[j]);
            }
            if (min_prev < INF) {
                g[i] = min(g[i], min_prev + costs[k]);
            }
        }
    }
    long long diff = g[M] - f[M];
    cout << diff;
    return 0;
}