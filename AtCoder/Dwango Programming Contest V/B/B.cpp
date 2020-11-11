#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;
const int N=1005;
int n;
long long k;
int a[N];
long long sum[N];
long long v[N*N];
int tot;
bool check(long long x)
{
	int cnt=0;
	for(int i=1;i<=tot;i++)
		if((v[i]&x)==x) cnt++;
	return cnt>=k;
}
int main()
{
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int l=1;l<=n;l++)
		for(int r=l;r<=n;r++)
			v[++tot]=sum[r]-sum[l-1];
	long long res=0;
	for(int i=60;i>=0;i--)
		if(check(res|(1LL<<i))) res|=1LL<<i;
	printf("%lld",res);
	return 0;
}
