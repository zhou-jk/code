#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000000;
const int MOD=1000000007;
int n,prime[N+1],mp[N+1],num[N+1],book[N+1];
void calc(int x,int val)
{
	int k=x;
	for(int i=1;prime[i]*prime[i]<=k;i++)
	    if(k%prime[i]==0)
	 	    while(k%prime[i]==0) num[i]++,k/=prime[i];
	if(k>1) num[mp[k]]++;
}
int main()
{
	for(int i=2;i<=N;i++)
    {
		if(!book[i]) prime[++prime[0]]=i,mp[i]=prime[0];
		for(int j=1;j<=prime[0];j++)
        {
			if(i*prime[j]>1000000) break;
			book[i*prime[j]]=true;
			if(i%prime[j]==0) break;
		}
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
        calc(i,1);
	long long ans=1;
	for(int i=1;i<=prime[0];i++) 
	    ans=ans*(num[i]*2ll+1)%MOD;
	printf("%lld",ans);
    return 0;
}