#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=605;
const int MOD=1000000007;
int n,k;
int match[N];
int c[N];
int f[N][N];
int g[N];
int dfs(int l,int r)
{
	if(l>r) return 0;
	if((r-l+1)%2!=0) return 0;
	if(f[l][r]!=-1) return f[l][r];
	for(int i=l;i<=r;i++)
		if(match[i])
		{
			if(match[i]<l||match[i]>r) return f[l][r]=0;
		}
	int res=g[c[r]-c[l-1]];
	for(int i=l+1;i<=r-1;i++)
		res=(res-1LL*dfs(l,i)*g[c[r]-c[i]]%MOD+MOD)%MOD;
	return f[l][r]=res;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		match[a]=b;
		match[b]=a;
	}
	n=n*2;
	for(int i=1;i<=n;i++)
		c[i]=c[i-1]+(match[i]==0);
	g[0]=1;
	for(int i=2;i<=n;i+=2)
		g[i]=1LL*g[i-2]*(i-1)%MOD;
	memset(f,-1,sizeof(f));
	int ans=0;
	for(int l=1;l<=n;l++)
		for(int r=l+1;r<=n;r++)
			ans=(ans+1LL*dfs(l,r)*g[c[n]-(c[r]-c[l-1])])%MOD;
	printf("%d",ans);
	return 0;
}