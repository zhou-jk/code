#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long n,m,s;
int maxx=-1,minn=1e9;
long long ans=1e18;
long long cnt;
long long sumn[200001],sumv[200001];
int v[200001],w[200001];
int l[200001],r[200001];
int check(int x)
{
    cnt=0;
    long long sum=0;
	memset(sumn,0,sizeof(sumn));
	memset(sumv,0,sizeof(sumv));
	for(int i=1;i<=n;i++)
		if(w[i]>=x) sumn[i]=sumn[i-1]+1,sumv[i]=sumv[i-1]+v[i];
		else sumn[i]=sumn[i-1],sumv[i]=sumv[i-1];
	for(int i=1;i<=m;i++)
		sum+=(sumn[r[i]]-sumn[l[i]-1])*(sumv[r[i]]-sumv[l[i]-1]);
	cnt=abs(sum-s);
	return sum>s;
}
int main()
{
    scanf("%lld%lld%lld",&n,&m,&s);
	for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&w[i],&v[i]);
		maxx=max(maxx,w[i]),minn=min(minn,w[i]);
	}
	for(int i=1;i<=m;i++)
        scanf("%d%d",&l[i],&r[i]);
	int l=minn-1,r=maxx+2,mid;
	while(l<=r)
    {
		mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
		ans=min(ans,cnt);
	}
	printf("%lld",ans);
    return 0;
}