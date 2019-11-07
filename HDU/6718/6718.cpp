#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int K=60;
const int MOD=998244353;
const int T=(1ll<<K)%MOD;
int n;
int b[100001],cnt;
bool vis[100001];
long long c[100001],dp[100001][2];
vector<long long>v;
vector<long long> num[K+1];
long long solve()
{
	vector<long long> num[K+1];
	long long book[K+1],ans=0;
	for(int i=0;i<=K;i++)
		book[i]=1;
	for(int i=0;i<v.size();i++)
	{
		long long x=v[i];
		for(int j=K;j>=0;j--)
			if((x>>j)&1) x^=1ll<<j,num[j].push_back(x);
			else book[j]=x%MOD*book[j]%MOD;
	}
	long long inv=1;
	for(int i=0;i<=K;i++)
		book[i]=book[i]*inv%MOD,inv=inv*(MOD+1)/2%MOD;
	for(int i=K;i>=0;i--)
	{
		for(int j=1;j<=num[i].size();j++)
			dp[j][0]=dp[j][1]=0;
		dp[0][0]=1;
		dp[0][1]=0;
		for(int j=1;j<=num[i].size();j++)
			for(int k=0;k<2;k++)
			{
				dp[j][k]=((1ll<<i)%MOD*dp[j-1][k]+dp[j][k])%MOD;
				dp[j][k^1]=(num[i][j-1]%MOD*dp[j-1][k]+dp[j][k^1])%MOD;
			}
		if(num[i].size()%2==0)
		{
			long long sum=1;
			for(int j=0;j<num[i].size();j++)
				sum=num[i][j]%MOD*sum%MOD;
			ans=((dp[num[i].size()][0]-sum+MOD)*book[i]%MOD+ans)%MOD;
		}
		else
		{
			ans=(dp[num[i].size()][0]*book[i]%MOD+ans)%MOD;
			break;
		}	
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&c[i]),c[i]++;
	long long ans=1;
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			cnt++;
			vector<long long> v;
			v.push_back(c[i]);
			for(int j=b[i];j!=i;j=b[j])
			{
				vis[j]=true;
				v.push_back(c[j]);
			}
			ans=ans*solve(v)%MOD;
		}
	for(int i=1;i<=cnt;i++)
		ans=ans*T%MOD;
	printf("%lld",ans);
	return 0;
}