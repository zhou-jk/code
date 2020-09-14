#include<iostream>
#include<cstdio>
using namespace std;
const int N=2005,M=6000;
int n,P;
int f[N*3][3][N*6];
int main()
{
	scanf("%d%d",&n,&P);
	n*=3;
	f[1][0][0+M]=1;
	for(int i=1;i<n;i++)
		for(int j=0;j<=2;j++)
			for(int k=-i;k<=i;k++)
			{
				if(j<=1) f[i+1][j+1][k+M]=(f[i+1][j+1][k+M]+1LL*f[i][j][k+M]*i%P)%P;
				if(j==0) f[i+1][0][k+1+M]=(f[i+1][0][k+1+M]+f[i][j][k+M])%P;
				else if(j==1) f[i+1][0][k-1+M]=(f[i+1][0][k-1+M]+f[i][j][k+M])%P;
				else if(j==2) f[i+1][0][k+M]=(f[i+1][0][k+M]+f[i][j][k+M])%P;
			}
	int ans=0;
	for(int k=0;k<=n;k+=3)
		ans=(ans+((long long)f[n][0][k-1+M]+f[n][1][k+1+M]+f[n][2][k+M])%P)%P;
	printf("%d",ans);
	return 0;
}
