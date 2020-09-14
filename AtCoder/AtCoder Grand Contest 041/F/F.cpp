#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=405;
const int MOD=998244353;
int n;
int h[N];
long long Pw[N];
long long C[N][N];
void init(int n=400)
{
	for(int i=0;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=n;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	}
	Pw[0]=1;
	for(int i=1;i<=n;i++)
		Pw[i]=Pw[i-1]*2%MOD;
	return;
}
long long f[N][N],g[N][N];
void dfs(int d,int l,int r)
{
	static long long tmpf[N],tmpg[N];
	for(int i=0;i<=r-l+1;i++)
		f[d][i]=g[d][i]=0;
	f[d][0]=g[d][0]=1;
	int pre=l,s=0;
	for(int i=l;i<=r;i++)
		if(h[i]==d)
		{
			if(pre<=i-1)
			{
				dfs(d+1,pre,i-1);
				int len=i-1-pre+1;
				for(int j=0;j<=s;j++)
					for(int k=0;k<=len;k++)
						tmpf[j+k]=(tmpf[j+k]+f[d][j]*f[d+1][k]%MOD)%MOD;
				for(int j=0;j<=s+len;j++)
					f[d][j]=tmpf[j],tmpf[j]=0;
				for(int j=0;j<=s;j++)
					for(int k=0;k<=len;k++)
						tmpg[j+k]=(tmpg[j+k]+g[d][j]*g[d+1][k]%MOD)%MOD;
				for(int j=0;j<=s+len;j++)
					g[d][j]=tmpg[j],tmpg[j]=0;;
				s+=len;
			}
			pre=i+1;
		}
	if(pre<=r)
	{
		dfs(d+1,pre,r);
		int len=r-pre+1;
		for(int j=0;j<=s;j++)
			for(int k=0;k<=len;k++)
				tmpf[j+k]=(tmpf[j+k]+f[d][j]*f[d+1][k]%MOD)%MOD;
		for(int j=0;j<=s+len;j++)
			f[d][j]=tmpf[j],tmpf[j]=0;
		for(int j=0;j<=s;j++)
			for(int k=0;k<=len;k++)
				tmpg[j+k]=(tmpg[j+k]+g[d][j]*g[d+1][k]%MOD)%MOD;
		for(int j=0;j<=s+len;j++)
			g[d][j]=tmpg[j],tmpg[j]=0;;
		s+=len;
	}
	int len=r-l+1,t=len-s;
	for(int i=0;i<=s;i++)
	{
		for(int j=0;j<=s-i;j++)
			tmpf[i+t+j]=(tmpf[i+t+j]+C[s-i][j]*(j?Pw[i+t]:(Pw[i+t]-1))%MOD*f[d][i]%MOD)%MOD;
		tmpf[i]=(tmpf[i]+g[d][i])%MOD;
		for(int j=0;j<=len-i;j++)
			tmpg[i+j]=(tmpg[i+j]+C[len-i][j]*Pw[i]%MOD*g[d][i]%MOD)%MOD;
	}
	for(int i=0;i<=len;i++)
	{
		f[d][i]=tmpf[i],tmpf[i]=0;
		g[d][i]=tmpg[i],tmpg[i]=0;
	}
	return;
}
int main()
{
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	dfs(1,1,n);
	printf("%lld",f[1][n]);
	return 0;
}
