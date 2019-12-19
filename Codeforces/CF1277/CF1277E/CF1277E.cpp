#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=200005,M=500005;
int T,n,m,a,b;
int f[N],cnt[N];
pair<int,int>t[M],p[N];
int getf(int v)
{
	if(v==f[v]) return v;
	f[v]=getf(f[v]);
	return f[v];
}
void merge(int u,int v)
{
	int f1=getf(u),f2=getf(v);
	if(f1!=f2) f[f2]=f1;
	return;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&a,&b);
		for(int i=1;i<=m;i++)
			scanf("%d%d",&t[i].first,&t[i].second);
		for(int i=1;i<=n;i++)
			f[i]=i;
		for(int i=1;i<=m;i++)
		{
			if(t[i].first==a||t[i].second==a) continue;
			merge(t[i].first,t[i].second);
		}
		for(int i=1;i<=n;i++)
			p[i].first=getf(i);
		for(int i=1;i<=n;i++)
			f[i]=i;
		for(int i=1;i<=m;i++)
		{
			if(t[i].first==b||t[i].second==b) continue;
			merge(t[i].first,t[i].second);
		}
		for(int i=1;i<=n;i++)
			p[i].second=getf(i);
		p[a].first=n+1,p[b].first=n+1;
		sort(p+1,p+n+1);
		memset(cnt,0,sizeof(cnt));
		long long ans=0;
		int j=1;
		for(int i=1;i<=n-2;i=j)
		{
			while(j<=n-2&&p[i].first==p[j].first) j++;
			for(int k=i;k<j;k++)
				ans+=i-1-cnt[p[k].second];
			for(int k=i;k<j;k++)
				cnt[p[k].second]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}