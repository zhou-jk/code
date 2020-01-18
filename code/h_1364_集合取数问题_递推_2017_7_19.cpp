#include <iostream>
#include <string.h>

using std::cin;
using std::cout;

int main() {
	int n,k;
	int f[1001][1001]; 
	cin >> n >> k;
	memset(f, 0, sizeof f);
	for (int i = 0; i <= n; i++) f[i][0] = 1;
	f[1][1] = 1;
	for (int i = 2; i <= n; i++) 
		for (int j = 1; j <= k && j <= i / 2 + 1; j++) { 
		    for (int p = 2 * j - 3; p < n - 1; p++) f[i][j] += f[p][j - 1];
		    f[i][j] %= 10007;
		} 
	cout << f[n][k];
	return 0;
} 
