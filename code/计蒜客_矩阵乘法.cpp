#include <iostream>
using namespace std;

int main() {
    int matrix_a[10][10];
    int matrix_b[10][10];
    int m;
    int n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix_a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix_b[i][j];
    int matrix_ans[10][10];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) {
            matrix_ans[i][j] = 0;
            for (int k = 0; k < n; k++)
                matrix_ans[i][j] += matrix_a[i][k] * matrix_b[k][j];
        }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m - 1; j++) 
            cout << matrix_ans[i][j] << ' ';
        cout << matrix_ans[i][m - 1] << endl;
    }
    return 0;
}
