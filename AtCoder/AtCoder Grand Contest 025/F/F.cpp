#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 5;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
char s[MAXN];
int n, m, k, a[MAXN], b[MAXN];
int l, resa[MAXN], resb[MAXN];
stack <pair <int, int>> stk;
int main() {
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
	read(n), read(m), read(k);
	scanf("%s", s + 1);
	for (int i = 1, j = n; i <= n; i++, j--)
		a[j] = s[i] - '0';
	scanf("%s", s + 1);
	for (int i = 1, j = m; i <= m; i++, j--)
		b[j] = s[i] - '0';
	for (int i = max(n, m); i >= 1; i--) {
		if (a[i] + b[i] == 1) stk.emplace(i, a[i] * 2 + b[i]);
		if (a[i] + b[i] <= 1) continue;
		int lft = k, pos = i, x = 3;
		stack <pair <int, int>> add;
		while (!stk.empty()) {
			pair <int, int> tmp = stk.top();
			if (pos == tmp.first) {
				stk.pop();
				if ((x ^ tmp.second) == 3) {
					x = 3;
					if (lft) lft--;
					else break;
				} else if (x == 3) {
					x &= tmp.second;
					add.emplace(tmp.first, tmp.second ^ 3);
				}
				pos += 1;
			} else if (x == 3) {
				if (tmp.first - pos > lft) break;
				lft -= tmp.first - pos;
				pos = tmp.first;
			} else break;
		}
		if (x == 3) resa[pos + lft] = resb[pos + lft] = 1;
		else add.emplace(pos, x);
		while (!add.empty()) {
			stk.push(add.top());
			add.pop();
		}
	}
	while (!stk.empty()) {
		pair <int, int> tmp = stk.top();
		resa[tmp.first] += (tmp.second >> 1) & 1;
		resb[tmp.first] += (tmp.second) & 1;
		stk.pop();
	}
	l = max(n, m) + k;
	while (resa[l] == 0) l--;
	for (int i = l; i >= 1; i--) putchar(resa[i] + '0');
	putchar('\n');
	l = max(n, m) + k;
	while (resb[l] == 0) l--;
	for (int i = l; i >= 1; i--) putchar(resb[i] + '0');
	putchar('\n');
	return 0;
}