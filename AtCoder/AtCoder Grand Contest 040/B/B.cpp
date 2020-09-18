#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
struct Seg
{
	int l,r;
}s[N];
int pre[N],nxt[N];
int main()
{
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&s[i].l,&s[i].r);
	sort(s+1,s+n+1,[=](const Seg &a,const Seg &b){return a.l==b.l?a.r<b.r:a.l<b.l;});
	pre[0]=1e9;
	for(int i=1;i<=n;i++)
		pre[i]=min(pre[i-1],s[i].r);
	nxt[n+1]=1e9;
	for(int i=n;i>=1;i--)
		nxt[i]=min(nxt[i+1],s[i].r);
	for(int i=1;i<n;i++)
		ans=max(ans,max(pre[i]-s[i].l+1,0)+max(nxt[i+1]-s[n].l+1,0));
	int L=s[n].l,R=pre[n];
	for(int i=1;i<=n;i++)
		ans=max(ans,s[i].r-s[i].l+1+max(R-L+1,0));
	printf("%d",ans);
	return 0;
}
