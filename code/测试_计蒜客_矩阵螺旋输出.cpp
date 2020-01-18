#include <iostream>
using namespace std;

int min1(int a, int b) {
  return a < b ? a : b; 
}
int main() {
    int matrix[100][100];
    int m;
    int n;
    int mi;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    mi = (min1(m, n) - 1) / 2;
    for (int i = 0; i <= mi; i++) {
        for (int j = i; j < n - i - 2; j++) {
            cout << matrix[i][j] << ' ';
        }
        if (n - i - 2 >= i) {
		    cout << matrix[i][n - i - 2];
		    cout << ' ';
	    } 
	    cout << matrix[i][n - i -1];
        for (int j = i + 1; j < m - i; j++) { //j <= m - i - 1
            cout << ' ' << matrix[j][n - i - 1];
        }
        if (m == 1 || n == 1 || i == mi && min1(n, m) % 2 == 1) break;
        for (int j = n - i - 2; j > i; j--) {  
            cout << ' ' << matrix[m - i - 1][j];
        }
        for (int j = m - i - 1; j > i; j--) {
            cout << ' ' << matrix[j][i];
        }
        if (i < mi) cout << ' ';
    }
    return 0;
}
