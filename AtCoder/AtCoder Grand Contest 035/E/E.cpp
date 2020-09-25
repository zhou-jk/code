#include<iostream>
#include<cstdio>
using namespace std;
const int N=305;
int n,K,P;
namespace subtask1
{
	long long f[N][N];
	int main()
	{
		f[0][0]=1;
		for(int i=1;i<=(n+1)/2;i++)
		{
			for(int j=0;j<=K/2;j++)
				f[i][0]=(f[i][0]+f[i-1][j])%P;
			for(int j=0;j<=K/2-1;j++)
				f[i][j+1]=(f[i][j+1]+f[i-1][j])%P;
		}
		long long ans1=0,ans0=0;
		for(int j=0;j<=K/2;j++)
			ans1=(ans1+f[(n+1)/2][j])%P;
		for(int j=0;j<=K/2;j++)
			ans0=(ans0+f[n/2][j])%P;
		printf("%lld",ans1*ans0%P);
		return 0;
	}
}
namespace subtask2
{
	long long f[N][N][N];
	int main()
	{
		f[0][0][0]=1;
		int i;
		for(i=2;i<=n+K;i+=2)
		{
			for(int j=0;j<=K+1;j++)
				for(int k=0;k<=n;k++)
					f[i][0][0]=(f[i][0][0]+f[i-2][j][k])%P;
			if(i<=n)
			{
				for(int j=0;j<=K+1;j++)
					for(int k=0;k<=n;k++)
						f[i][0][k+1]=(f[i][0][k+1]+f[i-2][j][k])%P;
			}
			if(i>=K+1)
			{
				for(int j=0;j<=K+1;j++)
					for(int k=0;k<=n;k++)
						f[i][j+(j!=0)][0]=(f[i][j+(j!=0)][0]+f[i-2][j][k])%P;
			}
			if(i<=n&&i>=K+1)
			{
				for(int j=0;j<=K+1;j++)
					for(int k=0;k<=n;k++)
						f[i][max(j+1,k+2)][k+1]=(f[i][max(j+1,k+2)][k+1]+f[i-2][j][k])%P;
			}
		}
		i-=2;
		long long ans=0;
		for(int j=0;j<=K+1;j++)
			for(int k=0;k<=n;k++)
				ans=(ans+f[i][j][k])%P;
		printf("%lld",ans);
		return 0;
	}
}
int main()
{
	scanf("%d%d%d",&n,&K,&P);
	if(K%2==0) return subtask1::main();
	else return subtask2::main();
	return 0;
}
