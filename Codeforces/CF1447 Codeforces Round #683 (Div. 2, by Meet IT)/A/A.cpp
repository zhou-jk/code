#include<iostream>
#include<cstdio>
using namespace std;
int T;
int n;
void solve()
{
	scanf("%d",&n);
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
		printf("%d ",i);
	printf("\n");
	return;
}
int main()
{
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
