#include<iostream>
#include<cstdio>
#include<vector>
#include<tuple>
using namespace std;
const int N=100005;
int n;
long long m;
int Q;
int fa[N];
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
		return true;
	}
	else return false;
}
int main()
{
	scanf("%d%lld%d",&n,&m,&Q);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	vector<tuple<int,int,int> >G;
	int num=0;
	for(int i=1;i<=Q;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		u++,v++;
		if(w==0) num+=merge(u,v);
		else if(w==1) G.push_back(make_tuple(u,v,w));
	}
	for(auto [u,v,w]:G)
		if(getf(u)==getf(v))
		{
			printf("No");
			return 0;
		}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(getf(i)==i) cnt++;
	if(cnt==2&&!G.empty())
	{
		printf("No");
		return 0;
	}
	long long l=num+cnt,r=num+1LL*cnt*(cnt-1)/2;
	if(cnt==1) l=num,r=num;
	if(G.empty()) l=num-1;
	if(l<=m&&m<=r) printf("Yes");
	else printf("No");
	return 0;
}
