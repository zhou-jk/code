#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n,m;
int a[N];
struct Edge
{
	int u,v,w;
}e[N];
int fa[N],siz[N];
long long sum[N];
int getf(int v)
{
	if(v==fa[v]) return v;
	fa[v]=getf(fa[v]);
	return fa[v];
}
void merge(int u,int v)
{
	int f1=getf(u),f2=getf(v);
	if(f1!=f2) fa[f2]=f1,siz[f1]+=siz[f2],sum[f1]+=sum[f2];
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+m+1,[=](const Edge &a,const Edge &b){return a.w<b.w;});
	for(int i=1;i<=n;i++)
		fa[i]=i,sum[i]=a[i];
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		merge(e[i].u,e[i].v);
		int f=getf(e[i].u);
		siz[f]++;
		if(sum[f]>=e[i].w) ans+=siz[f],siz[f]=0;
	}
	printf("%d",m-ans);
	return 0;
}
