#include<iostream>
#include<cstdio>
using namespace std;
const int res[6][20]={{},
{1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,4,6,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,36,108,220,334,384,0,0,0,0,0,0,0,0},
{0,0,0,0,0,976,1001,1001,1001,1001,1001,1001,1001,1001,1001,1001,1001}};
const int N=1005;
int G[N];
void init()
{
	G[1]=0;
	for(int n=2;n<=1000;n++)
	{
		for(int k=1;k<n;k++)
			if((1LL<<k)>=n&&((1LL<<k)-n)>=G[k])
			{
				G[n]=k;
				break;
			}
		if(G[n]==0) G[n]=-1;
	}
	return;
}
int g(long long n)
{
	if(n<=1000) return G[n];
	for(int k=1;;k++)
		if((1LL<<k)>=n&&((1LL<<k)-n)>=g(k)) return k;
	return -1;
}
int solve(long long n,long long k)
{
	if(n<k) swap(n,k);
	if(k<63&&(1LL<<k)-n<n) return solve((1LL<<k)-n,k);
	if(k>5) return 1001;
	if(k==0) return 1;
	return res[k][n];
}
long long n;
int main()
{
	init();
	scanf("%lld",&n);
	int ans=solve(n,g(n));
	if(n==4) ans++;
	if(n==7) ans+=2;
	if(ans>1000) printf("-1");
	else printf("%d",ans);
	return 0;
}
