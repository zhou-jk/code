#include<iostream>
#include<cstdio>
using namespace std;
const int INF=1061109567;
int n;
int a[200002],b[200002],c[200002];
long long ans,tot;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[0]=a[n+1]=INF;
	b[1]=INF;
	for(int i=2;i<=n;i++)
		b[i]=min(a[i-1],b[i-1])+10;
	for(int i=n-1;i>=1;i--)
		b[i]=min(b[i],min(a[i+1],b[i+1])+10);
	long long ans=0;
	for(int i=1;i<=n;i++)
		ans+=min(a[i],b[i]);
	for(int i=1;i<=n;i++)
		if(a[i]<b[i])
		{
			int l=i-1;
			while(l>0&&a[l]>b[l]) l--;
			int r=i+1;
			while(r<=n&&a[r]>b[r])r++;
			int x=a[i];
			a[i]=INF;
			for(int j=l+1;j<=r-1;j++)
				c[j]=0;
			c[l]=a[l];
			for(int j=l+1;j<r;j++)
				c[j]=min(a[j],c[j-1]+10);
			c[r]=a[r];
			for(int j=r-1;j>l;j--)
				c[j]=min(c[j],c[j+1]+10);
			long long sum=0;
			for(int j=l+1;j<r;j++)
				if(i!=j) sum+=c[j]-min(a[j],b[j]);
				else sum+=c[j]-x;
			tot=max(tot,sum);
			a[i]=x;
		}
	printf("%lld",ans+tot);
	return 0;
}