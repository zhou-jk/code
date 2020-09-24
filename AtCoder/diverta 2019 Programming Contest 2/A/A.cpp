#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	if(k==1) printf("0");
	else printf("%d",n-k);
	return 0;
}
