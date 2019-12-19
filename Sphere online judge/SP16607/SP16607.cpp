#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=11;
const int MOD=2004;
bool book[N];
int n,a,b;
int m[N];
const int prime[5]={0,2,3,5,7};
long long C(int n,int m)
{
	long long res=1;
	if(m>n) return 0;
    int cnt[5];
    memset(cnt,0,sizeof(cnt));
	for(int i=2;i<=m;i++)
    {
        for(int j=1;j<=4;j++)
            for(int k=i;k%prime[j]==0;k/=prime[j])
                cnt[j]++;
	}
	for(int i=n,j=1;j<=m;i--,j++)
    {
        int t=i;
        for(int j=1;j<=4;j++)
            while(t%prime[j]==0&&cnt[j])
                cnt[j]--,t/=prime[j];
		res=res*t%MOD;
	}
	return res;
}
long long ans;
void dfs(int k,bool flag,int tot)
{
	if(tot<0) return;
	if(k>n)
    {
		if(flag&1) ans=(ans-C(tot+n,n)+MOD)%MOD;
        else ans=(ans+C(tot+n,n))%MOD;
		return;
	}
	book[k]=false;
	dfs(k+1,flag,tot);
	book[k]=true;
	dfs(k+1,flag^1,tot-m[k]-1);
    return;
}
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++)
        scanf("%d",&m[i]);
	dfs(1,false,b);
	dfs(1,true,a-1);
	printf("%lld",ans);
	return 0;
}