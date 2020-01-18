//WA 遇到长于8位的数字会输出整个数再输出空格 而printf("%8d ",a)会自动挤占后面空格
#include <iostream>

using std::cin;
using std::cout;

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	//cout.setf(std::ios::right); 设置cout为右对齐(一直有效)(默认右对齐)  std::ios::left 左对齐
	cout.width(8); //设置宽度为8 仅对下一个cout有效
	cout<<a<<" ";
	cout.width(8);
	cout<<b<<" ";
	cout.width(8);
	cout<<c;
	return 0;
}
