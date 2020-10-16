#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=50005,M=1000005;
int n,m,Q;
int mod;
int x[N],y[N],z[N];
bool Pw[M][2];
int Get(int x,int y,int z)
{
	return (x-1)*6+y*3+z+1;
}
struct Union_Set
{
	int fa[N*6];
	void init(int n)
	{
		for(int i=1;i<=n;i++)
			fa[i]=i;
		return;
	}
	int getf(int v)
	{
		if(v==fa[v]) return v;
		fa[v]=getf(fa[v]);
		return fa[v];
	}
	void merge(int u,int v)
	{
		int f1=getf(u),f2=getf(v);
		if(f1!=f2) fa[f2]=f1;
		return;
	}
}S;
int main()
{
	scanf("%d%d%d%d",&n,&m,&Q,&mod);
	S.init(6*n);
	int g=mod;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		g=__gcd(g,abs(z[i]-z[1]));
	}
	mod=__gcd(mod,3*g);
	int r=z[1]%g;
	for(int i=1;i<=m;i++)
	{
		int c=(z[i]-r)/g%3;
		for(int p=0;p<=1;p++)
			for(int q=0;q<=2;q++)
			{
				S.merge(Get(x[i],p,q),Get(y[i],p^1,(2*q+c)%3));
				S.merge(Get(y[i],p,q),Get(x[i],p^1,(2*q+c)%3));
			}
	}
	int x=r;
	for(int i=0;i<=mod;i++)
		Pw[x][i&1]=true,x=x*2%mod;
	while(Q--)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		bool ans=false;
		for(int p=0;p<=1;p++)
			for(int q=0;q<=2;q++)
				if(Pw[(r+z+(3-q)*g)%mod][p])
				{
					if(S.getf(Get(y,0,0))==S.getf(Get(x,p,q))) ans=true;
				}
		if(ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
