#include <iostream>

using std::cin;
using std::cout; 

int main(){
	int n,k;
	long long f[31][31];
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		f[i][1] = 1;
		f[i][i] = 1;
	}
	for (int i = 3; i <= n; i++) 
		for (int j = 2; j <= k && j < i; j++) f[i][j] = f[i - 1][j - 1] + j * f[i - 1][j];
	cout << f[n][k];
	return 0;
}
