#include<iostream>
#include<cstdio>
using namespace std;
int x;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	scanf("%d",&x);
	printf("%d",360/gcd(x,360));
	return 0;
}
