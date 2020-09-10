#include<iostream>
#include<cstdio>
using namespace std;
int h,w,n;
int main()
{
	scanf("%d%d%d",&h,&w,&n);
	if(h<w) swap(h,w);
	printf("%d",(n+h-1)/h);
	return 0;
}
