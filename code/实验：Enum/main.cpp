#include <iostream>

using std::cout;
using std::endl;

int main()
{
	{ //同一作用域下不能有两个相同的枚举类型(如Sun)
		//例1
		enum day
		{
			Sun,
			Mon,
			Tue,
			Wed,
			Thu,
			Fri,
			Sat
		}; //定义一个day的枚举
		day d = Sun;
		// d只能等于"Sun,Mon,Tue,Wed,Thu,Fri,Sat"中的一个,没有其它值!
		cout << "value is " << d << endl;
		// 0
	}
	{
		//例2
		enum
		{
			Sun,
			Mon,
			Tue,
			Wed,
			Thu,
			Fri,
			Sat
		} d;
		d = Mon;
		cout << "value is " << d << endl;
		// 1
	}
	{
		//例3
		enum
		{
			Sun = 10,
			Mon,
			Tue,
			Wed,
			Thu,
			Fri,
			Sat
		} d1,
			d2, d3, d4;
		d1 = Sun;
		d2 = Mon;
		d3 = Tue;
		d4 = Wed;
		cout << d1 << " " << d2 << " " << d3 << " " << d4 << endl;
		//输出 10 11 12 13
	}
	{
		//例4
		enum
		{
			Sun = 10,
			Mon = 1,
			Tue,
			Wed,
			Thu,
			Fri,
			Sat
		} d1,
			d2, d3, d4;
		d1 = Sun;
		d2 = Mon;
		d3 = Tue;
		d4 = Wed;
		cout << d1 << " " << d2 << " " << d3 << " " << d4 << endl;
		//输出 10 1 2 3
	}
	{
		//例5
		enum
		{
			Sun = 2,
			Mon = 1,
			Tue,
			Wed,
			Thu,
			Fri,
			Sat
		} d1,
			d2, d3, d4;
		d1 = Sun;
		d2 = Mon;
		d3 = Tue;
		d4 = Wed;
		cout << d1 << " " << d2 << " " << d3 << " " << d4 << endl;
		//输出 2 1 2 3
	}
	return 0;
}