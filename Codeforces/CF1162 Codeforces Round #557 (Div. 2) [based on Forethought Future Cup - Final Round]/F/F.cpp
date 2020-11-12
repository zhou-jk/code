#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=2005;
const int MOD=998244353;
long long pw[N];
int n;
char s[N];
int fa[N];
int getf(int v)
{
	if(v==fa[v]) return v;
	else return fa[v]=getf(fa[v]);
}
void merge(int u,int v)
{
	int f1=getf(u),f2=getf(v);
	if(f1!=f2) fa[f2]=f1;
	return;
}
int ida[N],idb[N];
int id[2],tot;
vector<int>G[N];
int col[N];
bool flag;
void dfs(int u)
{
	for(int v:G[u])
	{
		if(col[v]!=-1)
		{
			if(col[v]==col[u])
			{
				flag=true;
				return;
			}
			else continue;
		}
		col[v]=col[u]^1;
		dfs(v);
		if(flag) return;
	}
	return;
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	id[0]=++tot;
	id[1]=++tot;
	for(int i=1;i<=n;i++)
		ida[i]=++tot,idb[i]=++tot;
	pw[0]=1;
	for(int i=1;i<=tot;i++)
		pw[i]=pw[i-1]*2%MOD;
	long long ans=0;
	for(int len=2;len<=n;len++)
	{
		for(int i=1;i<=tot;i++)
			fa[i]=i,col[i]=-1,G[i].clear();
		merge(ida[len],id[1]);
		merge(idb[1],id[1]);
		for(int i=1;i<len;i++)
			merge(ida[i],id[0]);
		for(int i=len;i<=n;i++)
			merge(ida[i],ida[n-(i-len+1)+1]);
		for(int i=1;i<=n;i++)
		{
			merge(idb[i],idb[n-i+1]);
			if(s[i]=='0') merge(ida[i],idb[i]);
		}
		G[getf(id[0])].emplace_back(getf(id[1])),G[getf(id[1])].emplace_back(getf(id[0]));
		for(int i=1;i<=n;i++)
			if(s[i]=='1') G[getf(ida[i])].emplace_back(getf(idb[i])),G[getf(idb[i])].emplace_back(getf(ida[i]));
		flag=false;
		int num=0;
		for(int i=1;i<=tot;i++)
			if(getf(i)==i&&col[i]==-1)
			{
				col[i]=0;
				dfs(i);
				if(flag) break;
				num++;
			}
		if(flag) continue;
		ans=(ans+pw[num-1])%MOD;
	}
	printf("%lld",ans);
	return 0;
}
