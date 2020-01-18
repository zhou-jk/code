#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

template <typename T>
class Array {
public:
    Array(int n):n(n){
        p = new T[n];
    }
    void insert(T u) {
        if (t < n) {
            *(p + t++) = u;
        } else {
            cout << "array full" << endl;
        }
    }
    void showAll() {
        for (int i = 0; i < t; i++) {
            cout << *(p + i) << endl;
        }
    }
private:
    T* p;
    int t = 0, n;
}; 

int main() {
    string str1="yangzhou301";
    Array<char> arr1(str1.length());
    for(auto c:str1)
    {
        arr1.insert(c);
    }
    arr1.showAll();
    int num[]={1,9,2,6,0,8,1,7};
    Array<int>arr2(sizeof(num)/sizeof(int));
    for(auto c:num)
    {
        arr2.insert(c);
    }
	arr2.showAll();
    arr2.insert(301);
    return 0;
}
