#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class People {
public:
    People(int new_num, string new_name, string new_gender, string new_ID, double new_salary):
    number(new_num), name(new_name), gender(new_gender), ID(new_ID), salary(new_salary) {
        cout << "calling the constructor" << endl;
    }
    People(People &p):number(p.number+1), name(p.name), gender(p.gender), ID(p.ID), salary(p.salary){ //可以number(p.number+1) 
        cout << "calling the copy constructor" << endl;
    }
    ~People(){
	    cout << "calling the destructor" << endl;
    }
    void set_name(string new_name) {
        name = new_name;
    }
    void set_salary(double new_salary) { //只有构造函数才能使用初始化列表,否则编译错误(析构函数也不行) 
        salary = new_salary;
    }
    void show(){ //函数都不能省略括号和大括号(任何时候) 
        cout << number << ' ' << name << ' ' << gender << ' ' << ID << ' ' << salary << endl;
    }
private:
    int number;
    string name, gender, ID;
    double salary;
};

int main() {
    People p1(01, "qratosone", "Male", "2010201326", 4800.0);
		People p2(p1);
		p2.set_name("He");
		p2.set_salary(301.301);
		p1.show();
		p2.show();
		string new_name;
		cin>>new_name;
		People p3(p2);
		p3.set_name(new_name);
		p3.show();
		return 0;
}
