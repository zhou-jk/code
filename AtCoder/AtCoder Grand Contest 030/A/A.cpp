#include<iostream>
#include<cstdio>
using namespace std;
int A,B,C;
int main()
{
	scanf("%d%d%d",&A,&B,&C);
	printf("%d",min(A+B+1,C)+B);
	return 0;
}
