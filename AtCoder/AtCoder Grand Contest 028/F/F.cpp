#include<iostream>
#include<cstdio>
using namespace std;
const int N=1505;
int n;
char s[N][N];
int sum[N][N],r[N][N];
int minp[2][N][N],maxp[2][N][N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	int cur=0;
	long long ans=0;
	for(int i=n;i>=1;i--)
	{
		cur^=1;
		for(int j=n;j>=1;j--)
			if(s[i][j]!='#')
			{
				sum[i][j]=sum[i][j+1]+sum[i+1][j]+s[i][j]-'0';
				r[i][j]=max(max(r[i][j+1],r[i+1][j]),i);
				minp[cur][j][i]=j;
				for(int k=i+1;k<=r[i+1][j];k++)
					minp[cur][j][k]=minp[cur^1][j][k];
				for(int k=max(r[i+1][j],i)+1;k<=r[i][j+1];k++)
					minp[cur][j][k]=minp[cur][j+1][k];
				maxp[cur][j][i]=j;
				for(int k=i;k<=r[i][j+1];k++)
					maxp[cur][j][k]=maxp[cur][j+1][k];
				for(int k=max(r[i][j+1],i)+1;k<=r[i+1][j];k++)
					maxp[cur][j][k]=maxp[cur^1][j][k];
				for(int k=i+1;k<=min(r[i][j+1],r[i+1][j]);k++)
					if(maxp[cur^1][j][k]>=minp[cur][j+1][k]) sum[i][j]-=sum[k][minp[cur][j+1][k]],k=r[k][minp[cur][j+1][k]];
				ans+=(s[i][j]-'0')*(sum[i][j]-(s[i][j]-'0'));
			}
	}
	printf("%lld",ans);
	return 0;
}