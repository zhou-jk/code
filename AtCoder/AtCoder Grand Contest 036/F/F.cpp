#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=505;
int n,P;
int l[N],r[N];
pair<int,int>a[N];
long long dp[N][N];
long long calc(int k)
{
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	int c1=0,c2=0;
	for(int i=0;i<n+n;i++)
		if(a[i].second==0)
		{
			for(int j=0;j<=c2;j++)
				dp[i+1][j]=(dp[i+1][j]+dp[i][j]*(a[i].first+1-(c1+j))%P)%P;
			c1++;
		}
		else
		{
			for(int j=0;j<=c2;j++)
				dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j]*(a[i].first+1-(c1+j))%P)%P;
			for(int j=0;j<=c2;j++)
				dp[i+1][j]=(dp[i+1][j]+dp[i][j]*(a[i].second+1-(n+k+(c2-j)))%P)%P;
			c2++;
		}
	return dp[n+n][k];
}
int main()
{
	scanf("%d%d",&n,&P);
	for(int i=0;i<n;i++)
		l[i]=max((int)ceil(sqrt(n*n-i*i)),0),r[i]=min((int)floor(sqrt(4*n*n-i*i)),n+n-1),a[i]=make_pair(l[i]-1,r[i]);
	for(int i=n;i<n+n;i++)
		l[i]=0,r[i]=sqrt(4*n*n-i*i),a[i]=make_pair(r[i],0);
	sort(a,a+n+n);
	long long ans=0;
	for(int i=n;i>=0;i--)
		if(i&1) ans=(ans-calc(i)+P)%P;
		else ans=(ans+calc(i))%P;
	printf("%lld",ans);
	return 0;
}
