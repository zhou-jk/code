#include<iostream>
#include<cstdio>
using namespace std;
const int N=15;
const int MOD=998244353;
int n,m;
long long ksm(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1) res=res*a%MOD;
		a=a*a%MOD,b>>=1;
	}
	return res;
}
long long fac[N],inv[N];
long long Pw[N];
void init(int n=10)
{
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%MOD;
	inv[n]=ksm(fac[n],MOD-2);
	for(int i=n;i>=1;i--)
		inv[i-1]=inv[i]*i%MOD;
	Pw[0]=1;
	for(int i=1;i<=n;i++)
		Pw[i]=Pw[i-1]*2%MOD;
	return;
}
long long C(int n,int m)
{
	if(m>n) return 0;
	else return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
int r[N],c[N];
char s[N][N];
long long f[N][N][3],g[N][N][3];
int main()
{
	init();
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			 if(s[i][j]=='.') r[i]|=1<<j,c[j]|=1<<i;
	for(int j=1;j<=m;j++)
		g[n][j][2]=C(m,j)*Pw[m-j]%MOD;
	long long ans=Pw[m];
	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--)
		{
			g[i][j][0]=(g[i][j][1]+g[i][j][2])%MOD;
			for(int k=1;k<i;k++)
			{
				int d=i-k;
				f[k][j][1]=(f[k][j][1]+C(i,d)*(g[i][j][2]*2+g[i][j][1])%MOD)%MOD;
				f[k][j][2]=(f[k][j][2]+C(i,d)*(Pw[d]-2)%MOD*g[i][j][2]%MOD)%MOD;
			}
			ans=(ans+g[i][j][2]*(Pw[i]-2)%MOD)%MOD;
			f[i][j][0]=(f[i][j][1]+f[i][j][2])%MOD;
			for(int k=1;k<j;k++)
			{
				int d=j-k;
				g[i][k][1]=(g[i][k][1]+C(j,d)*(f[i][j][2]*2+f[i][j][1])%MOD)%MOD;
				g[i][k][2]=(g[i][k][2]+C(j,d)*(Pw[d]-2)%MOD*f[i][j][2]%MOD)%MOD;
			}
			ans=(ans+f[i][j][2]*(Pw[j]-2)%MOD)%MOD;
		}
	for(int i=1;i<(1<<n);i++)
		for(int j=1;j<(1<<m);j++)
		{
			bool flag=true;
			for(int k=0;k<n;k++)
				if(i&(1<<k))
				{
					int w=r[k]&j;
					if(w==j||w==0)
					{
						flag=false;
						break;
					}
				}
			if(!flag) continue;
			for(int k=0;k<m;k++)
				if(j&(1<<k))
				{
					int w=c[k]&i;
					if(w==i||w==0)
					{
						flag=false;
						break;
					}
				}
			if(!flag) continue;
			int x=__builtin_popcount(i),y=__builtin_popcount(j);
			ans=(ans+(f[x][y][0]+g[x][y][0])%MOD*ksm(C(n,x),MOD-2)%MOD*ksm(C(m,y),MOD-2)%MOD)%MOD;
		}
	printf("%lld",ans);
	return 0;
}
