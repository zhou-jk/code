#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005;
int T;
int n,c[2],h;
int a[N];
void solve()
{
	scanf("%d%d%d%d",&n,&c[0],&c[1],&h);
	for(int i=1;i<=n;i++)
		scanf("%1d",&a[i]);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int t=c[a[i]];
		t=min(t,c[a[i]^1]+h);
		ans+=t;
	}
	printf("%d\n",ans);
	return;
}
int main()
{
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
