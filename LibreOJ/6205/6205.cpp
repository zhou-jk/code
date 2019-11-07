#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=1061109567;
const int SIZE=8;
int n,q;
int a[40001],b[40001];
int f[40001][17],dep[40001],sum[5000][1<<SIZE],Log[1<<SIZE];
struct Bitset
{
	static const int SIZE=625;
	unsigned long long b[SIZE];
	void set(int x)
	{
		b[x>>6]|=1ull<<(x&63);
		return;
	}
	Bitset operator ^=(const Bitset &B)
	{
		for(int i=0;i<SIZE;i++)
			b[i]^=B.b[i];
		return *this;
	}
}val[40001];
struct Edge
{
	int to,next;
}edge[80001];
int head[40001],cnt;
void add_edge(int u,int v)
{
	cnt++;
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt;
	return;
}
void dfs(int u,int father)
{
	f[u][0]=father;
	for(int i=1;(1<<i)<=n;i++)
		f[u][i]=f[f[u][i-1]][i-1];
	dep[u]=dep[f[u][0]]+1;
	val[u]=val[f[u][0]];
	val[u].set(a[u]);
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v==father) continue;
		dfs(v,u);
	}
	return;
}
int query(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=log2(n);i>=0;i--)
	{
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
		if(x==y) return x;
	}
	for(int i=log2(n);i>=0;i--)
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
void init()
{
	Log[1]=0;
	for(int i=2;i<(1<<SIZE);i++)
		Log[i]=Log[i>>1]+1;
	for(int i=0;i<n;i+=SIZE)
		for(int j=1;j<(1<<SIZE);j++)
		{
			int k=j&(j-1);
			if(k) sum[i>>3][j]=min(sum[i>>3][k],b[i+Log[k&-k]]-b[i+Log[j&-j]]);
			else sum[i>>3][j]=INF;
		}
	return;
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i-1]=a[i];
	}
	sort(b,b+n);
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(b,b+n,a[i])-b;
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	dfs(1,0);
	init();
	int ans=0;
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x=(x+ans)%n+1,y=(y+ans)%n+1;
		if(x==y)
		{
			ans=-1;
			printf("-1\n");
			continue;
		}
		int lca=query(x,y);
		Bitset S=val[x];
		S^=val[y];
		S.set(a[lca]);
		int ls=0;
		ans=INF;
		for(int i=0,j=0;i<n;i+=SIZE)
		{
			int k=(S.b[i>>6]>>(i&63))&((1<<SIZE)-1);
			if(!k) continue;
			ans=min(ans, sum[i>>3][k]);
			if (ls) ans=min(ans,b[i+Log[k&-k]]-b[j+Log[ls]]);
			ls=k,j=i;
		}
        if(ans>=INF) ans=-1,printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
