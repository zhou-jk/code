#include<iostream>
#include<cstdio>
using namespace std;
int A,B,C;
int main()
{
	scanf("%d%d%d",&A,&B,&C);
	if(A==B&&B==C) printf("Yes");
	else printf("No");
	return 0;
}
