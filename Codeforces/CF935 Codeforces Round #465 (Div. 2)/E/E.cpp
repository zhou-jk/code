#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=10005,M=105;
int n;
char s[N];
int p,m;
int lim;
int dp[2][N][M];
int ch[N][2],tot=1;
int fa[N];
void dfs(int u)
{
	if(!ch[u][0]) return;
	dfs(ch[u][0]);
	dfs(ch[u][1]);
	for(int i=0;i<=lim;i++)
		for(int j=0;i+j<=lim;j++)
		{
			dp[0][u][i+j+(p<m)]=max(dp[0][u][i+j+(p<m)],dp[0][ch[u][0]][i]+dp[0][ch[u][1]][j]);
			dp[0][u][i+j+(p>=m)]=max(dp[0][u][i+j+(p>=m)],dp[0][ch[u][0]][i]-dp[1][ch[u][1]][j]);
			dp[1][u][i+j+(p<m)]=min(dp[1][u][i+j+(p<m)],dp[1][ch[u][0]][i]+dp[1][ch[u][1]][j]);
			dp[1][u][i+j+(p>=m)]=min(dp[1][u][i+j+(p>=m)],dp[1][ch[u][0]][i]-dp[0][ch[u][1]][j]);
		}
	return;
}
int main()
{
	scanf("%s",s+1);
	scanf("%d%d",&p,&m);
	n=strlen(s+1);
	lim=min(p,m);
	memset(dp[0],-63,sizeof(dp[0]));
	memset(dp[1],63,sizeof(dp[1]));
	tot=1;
	int pre=tot;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='('||s[i]=='?')
		{
			ch[pre][ch[pre][0]?1:0]=++tot;
			fa[tot]=pre;
			pre=tot;
		}
		else if(s[i]==')') pre=fa[pre];
		else dp[0][tot][0]=dp[1][tot][0]=s[i]-'0',pre=fa[pre];
	}
	dfs(1);
	printf("%d",dp[0][1][lim]);
	return 0;
}
