#include <iostream>
using namespace std;

int main() {
	int b;
	b = 1; 
	int &a = b;
	cout << a << b << endl;
	a = 2;
	cout << a << b << endl; 
	return 0;
}
