//WA ��������8λ�����ֻ����������������ո� ��printf("%8d ",a)���Զ���ռ����ո�
#include <iostream>

using std::cin;
using std::cout;

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	//cout.setf(std::ios::right); ����coutΪ�Ҷ���(һֱ��Ч)(Ĭ���Ҷ���)  std::ios::left �����
	cout.width(8); //���ÿ��Ϊ8 ������һ��cout��Ч
	cout<<a<<" ";
	cout.width(8);
	cout<<b<<" ";
	cout.width(8);
	cout<<c;
	return 0;
}
