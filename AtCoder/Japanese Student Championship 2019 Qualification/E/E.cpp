#include<iostream>
#include<cstdio>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
const int N=200005;
int n,m,h,w;
int fa[N];
vector<tuple<int,int,int> >G;
bool isc[N];
int getf(int v)
{
	if(v==fa[v]) return v;
	fa[v]=getf(fa[v]);
	return fa[v];
}
int merge(int u,int v)
{
	int f1=getf(u),f2=getf(v);
	if(f1!=f2)
	{
		if(isc[f1]&&isc[f2]) return -1;
		else
		{
			fa[f2]=f1;
			isc[f1]|=isc[f2];
			return 1;
		}
	}
	else if(!isc[f1])
	{
		isc[f1]=true;
		return 0;
	}
	else return -1;
}
int main()
{
	scanf("%d%d%d",&n,&h,&w);
	for(int i=1;i<=n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		v+=h;
		G.push_back(make_tuple(u,v,w));
	}
	sort(G.begin(),G.end(),[=](const tuple<int,int,int>&x,const tuple<int,int,int>&y){return get<2>(x)>get<2>(y);});
	m=h+w;
	for(int i=1;i<=m;i++)
		fa[i]=i,isc[i]=false;
	long long ans=0;
	for(auto [u,v,w]:G)
		if(merge(u,v)!=-1) ans+=w;
	printf("%lld",ans);
	return 0;
}
