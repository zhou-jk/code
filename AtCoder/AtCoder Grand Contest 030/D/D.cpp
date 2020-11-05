#include<iostream>
#include<cstdio>
using namespace std;
const int N=3005;
const int MOD=1000000007;
int n,Q;
int a[N];
int x[N],y[N];
long long f[N][N];
long long g[N][N];
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
long long Pw[N];
void init(int n=3000)
{
	Pw[0]=1;
	for(int i=1;i<=n;i++)
		Pw[i]=Pw[i-1]*2%MOD;
	return;
}
int main()
{
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=Q;i++)
		scanf("%d%d",&x[i],&y[i]);
	init();
	long long inv2=ksm(2,MOD-2);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i]>a[j]) f[i][j]=1;
	for(int i=1;i<=Q;i++)
	{
		for(int j=1;j<=n;j++)
			g[x[i]][j]=f[x[i]][j],g[j][x[i]]=f[j][x[i]],g[y[i]][j]=f[y[i]][j],g[j][y[i]]=f[j][y[i]];
		for(int j=1;j<=n;j++)
			if(j!=x[i]&&j!=y[i])
			{
				f[x[i]][j]=(f[x[i]][j]*inv2%MOD+g[y[i]][j]*inv2%MOD)%MOD;
				f[j][x[i]]=(f[j][x[i]]*inv2%MOD+g[j][y[i]]*inv2%MOD)%MOD;
				f[y[i]][j]=(f[y[i]][j]*inv2%MOD+g[x[i]][j]*inv2%MOD)%MOD;
				f[j][y[i]]=(f[j][y[i]]*inv2%MOD+g[j][x[i]]*inv2%MOD)%MOD;
			}
		f[x[i]][y[i]]=(f[x[i]][y[i]]*inv2%MOD+g[y[i]][x[i]]*inv2%MOD)%MOD;
		f[y[i]][x[i]]=(f[y[i]][x[i]]*inv2%MOD+g[x[i]][y[i]]*inv2%MOD)%MOD;
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ans=(ans+Pw[Q]*f[i][j]%MOD)%MOD;
	printf("%lld",ans);
	return 0;
}
