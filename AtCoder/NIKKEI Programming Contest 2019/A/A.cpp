#include<iostream>
#include<cstdio>
using namespace std;
int n,A,B;
int main()
{
	scanf("%d%d%d",&n,&A,&B);
	printf("%d %d",min(A,B),max(A+B-n,0));
	return 0;
}
