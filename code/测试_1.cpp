#include <iostream>

using namespace std;

int main() {
    int a[10], b; //a��10������,b��Ҫ���ҵ���
    for (int i = 0; i < 10; i++) cin >> a[i]; //����10������
    cin >> b;  //����b
    for (int i = 0; i < 10; i++)
        if (a[i] == b) {
            cout << "YES" << endl;
            return 0;
        }
    cout << "NO" << endl;
    return 0;
}
