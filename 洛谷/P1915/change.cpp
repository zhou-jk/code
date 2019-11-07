#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("nemo1.out","r",stdin);
	freopen("temp.txt","w",stdout);
	printf("\"");
	string s;
	while(getline(cin,s));
		cout<<s<<"\\n";
	printf("\"");
	return 0;
}
