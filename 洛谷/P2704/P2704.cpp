#include<iostream> 
using namespace std;
int n,m,t,sum,tot;
char ch;
int map[101][11];
int s[201],num[201],v[101];
int dp[101][201][201];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			for(ch=getchar();ch!='P'&&ch!='H';ch=getchar());
			if(ch=='H') v[i]+=1<<j-1; 
		}
	for(int i=0;i<(1<<m);i++) 
	{
		if((i&(i<<1))||i&(i<<2)) continue;
		s[++tot]=i;
		for(int j=i;j;j>>=1) 
			num[tot]+=(1&j);
	}
	for(int i=1;i<=tot;i++)
        if(!(s[i]&v[1])) dp[1][1][i]=num[i];
	for(int i=1;i<n;i++)
		for(int j=1;j<=tot;j++)
			for(int k=1;k<=tot;k++)
				if(!(s[j]&s[k])&&dp[i][j][k])
					for(int l=1;l<=tot;l++)
					    if(!(s[j]&s[l])&&!(s[l]&s[k])&&!(s[l]&v[i+1])) dp[i+1][k][l]=max(dp[i+1][k][l],dp[i][j][k]+num[l]);
	for(int i=1;i<=tot;i++)
		for(int j=1;j<=tot;j++) 
		    sum=max(sum,dp[n][i][j]);
	printf("%d",sum);
    return 0;
}