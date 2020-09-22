#include<iostream>
#include<cstdio>
using namespace std;
const int N=1505;
const int MOD=998244353;
int n;
char s[N][N];
struct Graph
{
	int n;
	int G[N][N];
	int fa[N];
	int d[N];
	int getf(int v)
	{
		if(v==fa[v]) return v;
		fa[v]=getf(fa[v]);
		return fa[v];
	}
	bool merge(int u,int v)
	{
		int f1=getf(u),f2=getf(v);
		if(f1!=f2)
		{
			fa[f2]=f1;
			d[f1]+=d[f2];
			d[f2]=0;
			return true;
		}
		else return false;
	}
	void init(int _n)
	{
		n=_n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				G[i][j]=-1;
		for(int i=1;i<=n;i++)
			fa[i]=i,d[i]=0;
		return;
	}
	bool add(int u,int v,int w)
	{
		if(w==-1) return true;
		if(G[u][v]!=-1) return G[u][v]==w;
		else
		{
			G[u][v]=G[v][u]=w;
			return true;
		}
	}
	long long solve()
	{
		int tot=0;
		for(int u=1;u<=n;u++)
			for(int v=u+1;v<=n;v++)
				if(G[u][v]==-1) tot++;
				else d[u]+=G[u][v],d[v]+=G[u][v];
		if(n%2==0)
		{
			long long ans=1;
			for(int i=1;i<=tot;i++)
				ans=ans*2%MOD;
			return ans;
		}
		for(int u=1;u<=n;u++)
			for(int v=u+1;v<=n;v++)
				if(G[u][v]==-1)
				{
					if(merge(u,v)) tot--;
				}
		for(int i=1;i<=n;i++)
			if(getf(i)==i&&d[i]%2==1) return 0;
		long long ans=1;
		for(int i=1;i<=tot;i++)
			ans=ans*2%MOD;
		return ans;
	}
};
Graph g[2];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		scanf("%s",s[i]+1);
	g[0].init(n/2+1),g[1].init((n+1)/2);
	for(int i=1;i<n;i++)
		for(int j=1;j<n;j++)
		{
			int u=(min(i+j,n-i+n-j)/2)+1,v=(max(i-j,j-i)/2)+1;
			int w=(s[i][j]=='o'?1:(s[i][j]=='w'?0:-1));
			if(!g[(i+j)&1].add(u,v,w))
			{
				printf("0");
				return 0;
			}
		}
	printf("%lld",g[0].solve()*g[1].solve()%MOD);
	return 0;
}
