#include<iostream>
#include<cstdio>
using namespace std;
int n;
int k[6];
int main()
{
	scanf("%d",&n);
	k[5]=n/100,n%=100;
	k[4]=n/20,n%=20;
	k[3]=n/10,n%=10;
	k[2]=n/5,n%=5;
	k[1]=n;
	int ans=0;
	for(int i=1;i<=5;i++)
		ans+=k[i];
	printf("%d",ans);
	return 0;
}
