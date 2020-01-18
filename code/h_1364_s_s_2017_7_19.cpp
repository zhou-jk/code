#include <iostream>
#include <string.h>
#include <algorithm>

using std::cin;
using std::cout;
using std::max;

int main() {
	int n,k;
    short int f[1001][1001];
	cin >> n >> k;
	memset(f, 0, sizeof f);
	for (int i = 0; i <= n; i++) f[i][0] = 1;
	f[1][1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= k; j++) f[i][j] = (f[i - 2][j - 1] + f[i - 1][j]) % 10007;
	cout << f[n][k];
	return 0;
}
