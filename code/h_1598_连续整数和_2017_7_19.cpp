#include <iostream>
using std::cin;
using std::cout;

int main() {
	int n,k,m; 
	cin >> n >> k;
	m = n / k;
	if (k % 2 == 0) m++; 
	for (int i = m - k / 2; i <= m + k / 2; i++) cout << i << ' ';
	return 0;
}
