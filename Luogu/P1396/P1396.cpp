#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=10005;
int n,m,s,t;
int fa[N];
struct Node
{
	int u,v,w;
}e[N<<1];
bool cmp(Node a,Node b)
{
	return a.w<b.w;
}
int getf(int v)
{
	if(fa[v]==v) return v;
	fa[v]=getf(fa[v]);
	return fa[v];
}
void merge(int u,int v)
{
	int f1=getf(u),f2=getf(v);
	if(f1!=f2) fa[f2]=f1;
	return;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		merge(e[i].u,e[i].v);
		if(getf(s)==getf(t))
		{
			printf("%d",e[i].w);
			return 0;
		}
	}
	return 0;
}
