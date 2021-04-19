#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
const int MOD=1000000007;
int n;
int a[N];
int inv[N];
int sum[N];
void init(int n=100000)
{
	inv[1]=1;
	for(int i=2;i<=n;i++)
		inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
	for(int i=1;i<=n;i++)
		sum[i]=(sum[i-1]+inv[i])%MOD;
	return;
}
int main()
{
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int facn=1;
	for(int i=1;i<=n;i++)
		facn=1LL*facn*i%MOD;
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=(ans+1LL*(sum[n-i+1]+sum[i]-1)*facn%MOD*a[i]+MOD)%MOD;
	printf("%d",ans);
	return 0;
}