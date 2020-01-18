#include <iostream>
using std::cout; 

void print(int i) { //不能直接访问 main 中的 i 
	cout << i;
}
int  main() {
	for (int i = 0; i < 100; i++) {
		print(i);
	}
	return 0;
} 
