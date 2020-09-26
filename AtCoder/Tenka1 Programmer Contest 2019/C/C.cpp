#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n;
char s[N];
int sum[N][2];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	sum[0][0]=sum[0][1]=0;
	for(int i=1;i<=n;i++)
	{
		sum[i][0]=sum[i-1][0],sum[i][1]=sum[i-1][1];
		if(s[i]=='.') sum[i][0]++;
		else if(s[i]=='#') sum[i][1]++;
	}
	int ans=n;
	for(int i=0;i<=n;i++)
		ans=min(ans,(i-sum[i][0])+(n-i-(sum[n][1]-sum[i][1])));
	printf("%d",ans);
	return 0;
}
