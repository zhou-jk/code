#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
const int MOD=998244353;
int n;
int a[N];
int cnt[20];
int count(int x)
{
	int cnt=0;
	while(x)
		x/=10,cnt++;
	return cnt;
}
long long calc1(int x,int tot)
{
	static int b[100];
	int l=0;
	long long res=0;
	while(x)
	{
		b[++l]=x%10,x/=10;
		if(tot) b[++l]=0,tot--;
	}
	for(int i=l;i>=1;i--)
		res=(res*10+b[i])%MOD;
	return res;
}
long long calc2(int x,int tot)
{
	static int b[100];
	int l=0;
	long long res=0;
	while(x)
	{
		if(tot) b[++l]=0,tot--;
		b[++l]=x%10;
		x/=10;
	}
	for(int i=l;i>=1;i--)
		res=(res*10+b[i])%MOD;
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),cnt[count(a[i])]++;
	long long ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=9;j++)
			ans=(ans+calc1(a[i],j)*cnt[j]%MOD+calc2(a[i],j)*cnt[j]%MOD)%MOD;
	printf("%lld",ans);
	return 0;
}
