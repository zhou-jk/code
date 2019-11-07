#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=50000;
int n,vis[50001],tot=0,cnt=0,ans[100000],prime[50001];
void get_prime()
{
	for(int i=2;i<=N;i++)
	{
		if(!vis[i]) prime[++tot]=i;
		for(int j=1;j<=tot&&prime[j]*i<=N;j++)
		{
			vis[prime[j]*i]=true;
			if(i%prime[j]==0) break;
		}
	}
	vis[1]=true;
    return;
} 
bool is_prime(long long x)
{
	if(x<=N) return !vis[x];
	for(long long i=2;i*i<=x;i++)
		if(x%i==0) return false;
	return true;
}
void dfs(long long k,int x,long long t)
{
	if(k==1)
	{
		ans[++cnt]=t;
		return;
	}
	if(k-1>=prime[x]&&is_prime(k-1)) ans[++cnt]=(k-1)*t;
	for(int i=x;i<=tot&&prime[i]*prime[i]<=k;i++)
	{
		long long tmp=prime[i];
		for(long long j=prime[i]+1;j<=k;tmp*=prime[i],j+=tmp)
			if(k%j==0) dfs(k/j,i+1,t*tmp);
	}
}
int main()
{
	long long S;
    get_prime();
	while(scanf("%lld",&S)!=EOF)
	{
		cnt=0;
		dfs(S,1,1);
		sort(ans+1,ans+1+cnt);
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++)
            printf("%d ",ans[i]);
		if(cnt) printf("\n");
	}
	return 0;
}