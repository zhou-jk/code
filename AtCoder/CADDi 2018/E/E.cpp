#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
const long long INF=4e18;
int n;
long long a[N],b[N];
int pre[N],nxt[N];
long long sp[N],sn[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		b[i]=a[i];
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		if(b[i]>0) b[i]*=-2,cnt++;
		if(i!=1&&b[i]<b[i-1])
		{
			while(b[i]<b[i-1])
			{
				int l=pre[i-1];
				while(l!=1&&b[l-1]>b[l]*4) pre[i-1]=pre[l-1],l=pre[i-1];
				cnt+=(i-1-l+1)*2;
				b[l]*=4;
				if(i-1!=l) b[i-1]*=4;
			}
		}
		if(i==1||b[i-1]<=b[i]*4) pre[i]=i;
		else pre[i]=pre[i-1];
		sp[i]=sp[i-1]+cnt;
	}
	for(int i=1;i<=n;i++)
		b[i]=a[i];
	for(int i=n;i>=1;i--)
	{
		int cnt=0;
		if(b[i]<0) b[i]*=-2,cnt++;
		if(i!=n&&b[i]>b[i+1])
		{
			while(b[i]>b[i+1])
			{
				int r=nxt[i+1];
				while(r!=n&&b[r+1]<b[r]*4) nxt[i+1]=nxt[r+1],r=nxt[i+1];
				cnt+=(r-(i+1)+1)*2;
				b[r]*=4;
				if(i+1!=r) b[i+1]*=4;
			}
		}
		if(i==n||b[i+1]>=b[i]*4) nxt[i]=i;
		else nxt[i]=nxt[i+1];
		sn[i]=sn[i+1]+cnt;
	}
	long long ans=INF;
	for(int i=0;i<=n;i++)
		ans=min(ans,sp[i]+sn[i+1]);
	if(ans>=INF) printf("-1");
	else printf("%lld",ans);
	return 0;
}
