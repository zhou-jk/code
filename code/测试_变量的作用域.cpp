#include <iostream>
using std::cout; 

void print(int i) { //����ֱ�ӷ��� main �е� i 
	cout << i;
}
int  main() {
	for (int i = 0; i < 100; i++) {
		print(i);
	}
	return 0;
} 
