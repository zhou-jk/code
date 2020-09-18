#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
int n,m,K;
int P;
int C[N][N];
int Pw[N][N*N];
int add(const int &x,const int &y)
{
	int t=x+y;
	if(t>=P) t-=P;
	return t;
}
int sub(const int &x,const int &y)
{
	int t=x-y;
	if(t<=0) t+=P;
	return t;
}
void init(int n=100)
{
	for(int i=0;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=add(C[i-1][j],C[i-1][j-1]);
	}
	for(int i=0;i<=n;i++)
	{
		Pw[i][0]=1;
		for(int j=1;j<=n*n;j++)
			Pw[i][j]=1LL*Pw[i][j-1]*i%P;
	}
	return;
}
int f[2][N][N];
int cur;
int main()
{
	scanf("%d%d%d",&n,&m,&K);
	scanf("%d",&P);
	init();
	int cur=0;
	f[0][0][0]=1;
	for(int k=1;k<=K;k++)
	{
		cur^=1;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				if(f[cur^1][i][j])
				{
					int pw=1LL*Pw[k][m-j]*Pw[K-k+1][j]%P,fac=f[cur^1][i][j];
					for(int a=0;i+a<=n;a++)
					{
						int res=1LL*C[n-i][a]*fac%P;
						f[cur][i+a][j]=add(f[cur][i+a][j],res);
						fac=1LL*fac*pw%P;
					}
				}
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				f[cur^1][i][j]=0;
		cur^=1;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				if(f[cur^1][i][j])
				{
					int pw=1LL*Pw[k][n-i]*Pw[K-k+1][i]%P,fac=f[cur^1][i][j];
					for(int b=0;j+b<=m;b++)
					{
						int res=1LL*C[m-j][b]*fac%P;
						f[cur][i][j+b]=add(f[cur][i][j+b],res);
						fac=1LL*fac*pw%P;
					}
				}
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				f[cur^1][i][j]=0;
		cur^=1;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				if(f[cur^1][i][j])
				{
					int pw=1LL*Pw[k][m-j]*Pw[K-k][j]%P,fac=f[cur^1][i][j];
					for(int c=0;i+c<=n;c++)
					{
						int res=1LL*C[n-i][c]*fac%P;
						if(c&1) f[cur][i+c][j]=sub(f[cur][i+c][j],res);
						else f[cur][i+c][j]=add(f[cur][i+c][j],res);
						fac=1LL*fac*pw%P;
					}
				}
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				f[cur^1][i][j]=0;
		cur^=1;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				if(f[cur^1][i][j])
				{
					int pw=1LL*Pw[k][n-i]*Pw[K-k][i]%P,fac=f[cur^1][i][j];
					for(int d=0;j+d<=m;d++)
					{
						int res=1LL*C[m-j][d]*fac%P;
						if(d&1) f[cur][i][j+d]=sub(f[cur][i][j+d],res);
						else f[cur][i][j+d]=add(f[cur][i][j+d],res);
						fac=1LL*fac*pw%P;
					}
				}
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				f[cur^1][i][j]=0;
	}
	printf("%d",f[cur][n][m]);
	return 0;
}

