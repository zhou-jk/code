#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;
int main() {
    cout<<3.0<<endl;
    cout<<setprecision(4)<<3.14159<<endl;
    cout<<setprecision(3)<<333333.14<<' '<<setprecision(2)<<333333.14<<endl;
    cout<<setprecision(4)<<333333.14<<endl;
	cout<<fixed<<setprecision(2)<<3.0<<' '<<3.14159<<' '<<fixed<<setprecision(2)<<3.14159<<endl;
    cout<<3.14159<<endl;
    /*system("rd /s /q E:\C++\1\bin");
    system("rd /s /q E:\C++\1\obj");*/
    return 0;
}
