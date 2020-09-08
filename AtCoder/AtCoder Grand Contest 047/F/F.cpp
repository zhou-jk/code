#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
const int N=200005;
const long long INF=1e18;
int n;
int x[N],y[N];
int pre[N],nxt[N];
struct Node
{
	int x,y,id;
}pos[N];
vector<int>val;
int id[N];
int dis(int a,int b)
{
	return abs(x[a]-x[b])+abs(y[a]-y[b]);
}
map<int,long long>dp[2][N];
long long solve(int l,int r,int side)
{
	if(dp[side][l][r]) return dp[side][l][r];
	long long res=INF;
	int Min=min(pos[l].y,pos[r].y);
	int Max=max(pos[l].y,pos[r].y);
	if(l>1&&(pos[l-1].y==Min-1||pos[l-1].y==Max+1))
	{
		int L=pre[l-1];
		long long tmp=solve(L,r,0)+dis(pos[L].id,pos[side?r:l].id);
		res=min(res,tmp);
	}
	if(r<n&&(pos[r+1].y==Min-1||pos[r+1].y==Max+1))
	{
		int R=nxt[r+1];
		long long tmp=solve(l,R,1)+dis(pos[R].id,pos[side?r:l].id);
		res=min(res,tmp);
	}
	if(res==INF) res=l-r;
	dp[side][l][r]=res;
	return res;
}
long long ans[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		val.push_back(y[i]);
		pos[i].x=x[i],pos[i].y=y[i],pos[i].id=i; 
	}
	sort(pos+1,pos+n+1,[](const Node &a,const Node &b){return a.x<b.x;}); 
	sort(val.begin(),val.end());
	for(int i=1;i<=n;i++)
		pos[i].y=lower_bound(val.begin(),val.end(),pos[i].y)-val.begin()+1;
	pre[1]=1;
	for(int i=2;i<=n;i++)
		if(abs(pos[i].y-pos[i-1].y)==1) pre[i]=pre[i-1];
		else pre[i]=i;
	nxt[n]=n;
	for(int i=n-1;i>=1;i--)
		if(abs(pos[i].y-pos[i+1].y)==1) nxt[i]=nxt[i+1];
		else nxt[i]=i;
	for(int i=1;i<=n;i++)
		ans[pos[i].id]=solve(i,i,0);
	for(int i=1;i<=n;i++)
		printf("%lld\n",ans[i]);
	return 0;
}
