#include<iostream>  
#include<vector>  
using namespace std;  
class A{  
    private:  
    int value;  
    public:  
    A(){  
    cout << "constructor " << endl;  
  
    }  
    A(int n){  
    value=n;  
    cout << "constructor " << endl;  
    }  
    A(A &o){//nonconst  
        this->value = o.value;  
        cout << "copy non const" << endl;  
    }  
  
  
    A(const A &other){//const  
    value = other.value;  
    cout << "copy const" << endl;   
    }  
/*  A(A o){ 
    value = o.value; 
    } 
*/  void print(){  
    cout << value << endl;  
    }  
};  
  
void print(A a){  
    a.print();  
}  
  
int main(){  
    A a(10);  
    A b = a;  
    A c(b);  
    b.print();  
    print(b);  
      
    vector<A> v(10);  
      
      
    return 0;  
}
