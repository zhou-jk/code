#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=401;
const int INF=1061109567;
int n;
int s[N],t[N];
int a[N],cnt;
int pre[N][N],suf[N][N];
int dp[N][N],f[N][N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&s[i],&t[i]);
        t[i]+=s[i];
        a[++cnt]=s[i],a[++cnt]=t[i];
    }
	sort(a+1,a+cnt+1);
	cnt=unique(a+1,a+cnt+1)-a-1;
	for(int i=1;i<=n;i++)
    {
		s[i]=lower_bound(a+1,a+cnt+1,s[i])-a,t[i]=lower_bound(a+1,a+cnt+1,t[i])-a;
		for(int l=1;l<=s[i];l++)
			for(int r=t[i];r<=cnt;r++)
                f[l][r]++;
	}
	for(int i=1;i<=cnt;i++)
		for(int j=1;j<=n;j++)
            pre[i][j]=suf[i][j]=-INF;
	for(int i=1;i<=cnt;i++)
		for(int j=0;j<=f[1][i];j++)
			for(int k=1;k<=i;k++)
            {
                pre[i][j]=max(pre[i][j],pre[k][j]+f[k][i]);
				if(j>=f[k][i]) pre[i][j]=max(pre[i][j],pre[k][j-f[k][i]]);
			}
	for(int i=cnt;i>0;i--)
		for(int j=0;j<=f[i][cnt];j++)
			for(int k=cnt;k>=i;k--)
            {
                suf[i][j]=max(suf[i][j],suf[k][j]+f[i][k]);
				if(j>=f[i][k]) suf[i][j]=max(suf[i][j],suf[k][j-f[i][k]]);
			}
	for(int l=1;l<=cnt;l++)
		for(int r=l;r<=cnt;r++)
			for(int x=0,y=f[r][cnt];x<=f[1][l];x++)
            {
				while(y>0&&min(x+y,pre[l][x]+f[l][r]+suf[r][y])<=min(x+y-1,pre[l][x]+f[l][r]+suf[r][y-1])) y--;
                dp[l][r]=max(dp[l][r],min(x+y,pre[l][x]+f[l][r]+suf[r][y]));
			}
	int ans=0;
	for(int i=1;i<=cnt;i++)
        for(int j=1;j<=f[1][i];j++)
            ans=max(ans,min(pre[i][j],j));
    printf("%d\n",ans);
	for(int i=1;i<=n;i++)
    {
		int res=0;
		for(int l=s[i];l>0;l--)
			for(int r=t[i];r<=cnt;r++)
                res=max(res,dp[l][r]);
		printf("%d\n",res);
	}
    return 0;
}