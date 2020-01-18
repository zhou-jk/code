#include <iostream>

using namespace std;

int main() {
    int a[10], b; //a是10个整数,b是要查找的数
    for (int i = 0; i < 10; i++) cin >> a[i]; //读入10个整数
    cin >> b;  //读入b
    for (int i = 0; i < 10; i++)
        if (a[i] == b) {
            cout << "YES" << endl;
            return 0;
        }
    cout << "NO" << endl;
    return 0;
}
