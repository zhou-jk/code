#include<iostream>
#include<cstdio>
using namespace std;
int n,p;
int x;
int tot,prime[20],num[20],cnt;
long long ans1=1,ans2=1;
long long ksm(long long a,long long b,long long mod)
{
    long long res=1;
    while(b)
    {
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}
void divide(int k)
{
	tot=k;
	for(int i=2;i*i<=k;i++)
        if(k%i==0)
        {
		    prime[++cnt]=i;tot=tot/i*(i-1);
		    while(k%i==0)
                k/=i;
	    }
	if(k>1) prime[++cnt]=k,tot=tot/k*(k-1);
    return;
}
int main()
{
    scanf("%d%d",&n,&p);
    divide(p);
	for(int i=1;i<=n;i++)
    {
		x=4*i-2;
		for(int j=1;j<=cnt;j++)
            while(x%prime[j]==0) num[j]++,x/=prime[j];
		ans1=ans1*x%p;
		x=i+1;
		for(int j=1;j<=cnt;j++)
            while(x%prime[j]==0) num[j]--,x/=prime[j];
		ans2=ans2*x%p;
	}
    ans1=ans1*ksm(ans2,tot-1,p)%p;
    for(int i=1;i<=cnt;i++)
        for(int j=1;j<=num[i];j++)
            ans1=ans1*prime[i]%p;
	printf("%lld",ans1);
	return 0;
}