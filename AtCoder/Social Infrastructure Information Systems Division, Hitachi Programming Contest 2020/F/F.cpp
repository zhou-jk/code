#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=200005;
const int MOD=998244353;
int n;
vector<int>G[N];
int s,t;
int Max,p;
int dep[N];
int fa[N];
void dfs(int u,int father)
{
	fa[u]=father;
	dep[u]=dep[father]+1;
	if(dep[u]>Max) Max=dep[u],p=u;
	for(int v:G[u])
	{
		if(v==father) continue;
		dfs(v,u);
	}
	return;
}
vector<int>pos;
int len;
long long f[N][3][3];
long long g[3][3];
void DP(int u,int father,int d)
{
	if(d==len/2) f[u][1][1]=1;
	else f[u][0][0]=1;
	for(int v:G[u])
	{
		if(v==father) continue;
		DP(v,u,d+1);
		for(int i=0;i<=2;i++)
			for(int j=0;j<=2;j++)
				for(int x=0;x<=2;x++)
					for(int y=0;y<=2;y++)
						for(int k=-1;k<=1;k++)
						{
							int p=min(2,i+x*(k==-1)),q=min(2,j+y*(k==1));
							g[p][q]=(g[p][q]+f[u][i][j]*f[v][x][y]%MOD)%MOD;
						}
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				f[u][i][j]=g[i][j],g[i][j]=0;
	}
	return;
}
long long ksm(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1) res=res*a%MOD;
		a=a*a%MOD,b>>=1;
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);
	s=p;
	Max=0;
	dfs(s,0);
	t=p;
	for(int u=t;u!=s;u=fa[u])
		pos.push_back(u);
	pos.push_back(s);
	len=pos.size()-1;
	if(len%2==0)
	{
		int x=pos[len/2];
		DP(x,0,0);
		printf("%lld",f[x][1][1]*ksm(2,MOD-2)%MOD);
	}
	else
	{
		int x=pos[(len-1)/2],y=pos[(len+1)/2];
		DP(x,y,0);
		DP(y,x,0);
		long long fx=(f[x][1][0]+f[x][1][1]+f[x][1][2])%MOD,fy=(f[y][0][1]+f[y][1][1]+f[y][2][1])%MOD;
		printf("%lld",fx*fy%MOD);
	}
	return 0;
}
