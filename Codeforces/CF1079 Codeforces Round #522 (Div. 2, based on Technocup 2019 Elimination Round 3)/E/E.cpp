#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int N=105;
map<pair<int,int>,int>dp,pre;
int n;
int a[N],cnt[N];
int C[N][N];
int main()
{
	scanf("%d",&n);
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(cnt[a[i]]==0) tot++;
		cnt[a[i]]++;
	}
	int m=*max_element(a+1,a+n+1);
	if(tot<=2)
	{
		printf("%d",n);
		return 0;
	}
	for(int i=0;i<=n;i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	dp[{0,0}]=pre[{0,0}]=1;
	for(int i=1;i<=n;i++)
	{
		for(auto [v,s]:pre)
			dp[{v.first+a[i],v.second+1}]+=s;
		pre=dp;
	}
	int ans=1;
	for(int w=1;w<=m;w++)
		for(int i=2;i<=cnt[w];i++)
			if(dp[{w*i,i}]==C[cnt[w]][i]) ans=max(ans,i);
	printf("%d",ans);
	return 0;
}
