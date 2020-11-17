#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	int ans=0;
	for(int i=1;i<=k;i++)
		ans+=2*(n-4*(i-1))+2*(m-4*(i-1))-4;
	printf("%d",ans);
	return 0;
}
