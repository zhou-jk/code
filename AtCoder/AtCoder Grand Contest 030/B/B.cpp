#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int L,n;
long long a[N];
long long sp[N];
long long sn[N];
long long calc1(int k)
{
	if((n-k+1)%2==0) return a[k]+(sn[k+(n-k+1)/2]*2-(L-a[k+(n-k+1)/2]))+(sp[k+(n-k+1)/2-1]-sp[k]-a[k]*(k+(n-k+1)/2-1-k))*2+a[k]*(n-k);
	else return a[k]+(sn[k+(n-k+1+1)/2]*2)+((sp[k+(n-k+1+1)/2-1]-sp[k]-a[k]*(k+(n-k+1+1)/2-1-k))*2-(a[k+(n-k+1+1)/2-1]-a[k]))+a[k]*(n-k);
}
long long calc2(int k)
{
	if(k%2==0) return (L-a[k])+(sp[k/2]*2-a[k/2])+(sn[k/2+1]-sn[k]-(L-a[k])*(k-(k/2+1)))*2+(L-a[k])*(k-1);
	else return (L-a[k])+(sp[k/2]*2)+((sn[k/2+1]-sn[k]-(L-a[k])*(k-(k/2+1)))*2-(a[k]-a[k/2+1]))+(L-a[k])*(k-1);
}
int main()
{
	scanf("%d%d",&L,&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		sp[i]=sp[i-1]+a[i];
	for(int i=n;i>=1;i--)
		sn[i]=sn[i+1]+(L-a[i]);
	long long ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,calc1(i));
	for(int i=1;i<=n;i++)
		ans=max(ans,calc2(i));
	printf("%lld",ans);
	return 0;
}
