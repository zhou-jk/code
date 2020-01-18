#include <iostream>

//using namespace std;

using std::cin;
using std::cout;
using std::endl;

int max(int a, int b) {
	return a > b ? a : b; 
} 

int min(int a, int b) {
	return a < b ? a : b; 
}


int main() {
	int x[4], y[4], l;
	for (int i = 0; i <= 3; i++) cin >> x[i] >> y[i];
	//for (int i = 0; i <= 3; i++) cout << x[i] << y[i] << endl;
	l = max(max(x[1], x[3])-min(x[0], x[2]), max(y[1], y[3])-min(y[0], y[2]));
	cout << l*l << endl;
	return 0;
}
