#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1000005;
const long long INF=4557430888798830399;
int n,m;
int a[N],b[N],c[N];
int fa[N];
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
int in[N],siz[N];
bool circle[N];
vector<int>pos[4];
long long s2[N],s0[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	long long ans=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		if(a[i]!=b[i]) ans++;
		merge(a[i],b[i]);
		in[a[i]]++;
	}
	memset(circle,true,sizeof(circle));
	for(int i=1;i<=n;i++)
	{
		siz[getf(i)]++;
		if(in[i]>1) circle[getf(i)]=false;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(getf(i)==i)
		{
			if(circle[i]&&siz[i]>1) cnt++;
		}
	if(cnt==0)
	{
		printf("%lld",ans);
		return 0;
	}
	ans+=cnt;
	for(int i=1;i<=m;i++)
		if(c[i]>=2)
		{
			int u=getf(a[i]);
			if(circle[u])
			{
				if(siz[u]==1) pos[0].push_back(c[i]-2);
				else if(siz[u]>1) pos[1].push_back(c[i]-1);
			}
			else
			{
				if(a[i]==b[i]) pos[2].push_back(c[i]-1);
				else pos[3].push_back(c[i]-1);
			}
		}
	for(int p=0;p<=3;p++)
		sort(pos[p].begin(),pos[p].end(),greater<int>());
	long long sum=0;
	for(int p=0;p<=3;p++)
		for(int c:pos[p])
			sum+=c;
	if(sum<cnt)
	{
		printf("-1");
		return 0;
	}
	if(pos[2].empty()&&pos[3].empty())
	{
		printf("-1");
		return 0;
	}
	if(pos[3].empty()) ans++,cnt-=pos[2].front(),pos[2].erase(pos[2].begin());
	else cnt-=pos[3].front(),pos[3].erase(pos[3].begin());
	for(int c:pos[3])
		cnt-=c;
	for(int c:pos[1])
		cnt-=c;
	pos[3].clear();
	pos[1].clear();
	if(cnt<=0)
	{
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=pos[0].size();i++)
		s0[i]=s0[i-1]+pos[0][i-1];
	for(int i=1;i<=pos[2].size();i++)
		s2[i]=s2[i-1]+pos[2][i-1];
	long long res=INF;
	for(int i=pos[0].size(),j=0;i>=0;i--)
	{
		while(j<=pos[2].size()&&s0[i]+s2[j]<cnt) j++;
		if(j<=pos[2].size()) res=min(res,2LL*i+j);
	}
	printf("%lld",ans+res);
	return 0;
}
