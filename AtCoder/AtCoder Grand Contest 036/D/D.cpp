#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=505;
const long long INF=4557430888798830399;
int n;
int a[N][N];
long long s1[N][N],s2[N][N];
long long f[N][N];
long long calc1(int l1,int r1,int l2,int r2)
{
	if(l1>r1) return 0;
	if(l2>r2) return 0;
	return s1[r1][r2]-s1[l1-1][r2]-s1[r1][l2-1]+s1[l1-1][l2-1];
}
long long calc2(int l1,int r1,int l2,int r2)
{
	if(l1>r1) return 0;
	if(l2>r2) return 0;
	return s2[r1][r2]-s2[l1-1][r2]-s2[r1][l2-1]+s2[l1-1][l2-1];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) scanf("%d",&a[i][j]);
	for(int i=1;i<=n+1;i++)
		for(int j=1;j<=n+1;j++)
		{
			s1[i][j]=s1[i-1][j]+s1[i][j-1]-s1[i-1][j-1];
			if(i>j) s1[i][j]+=a[i][j];
			s2[i][j]=s2[i-1][j]+s2[i][j-1]-s2[i-1][j-1];
			if(i<j) s2[i][j]+=a[i][j];
		}
	memset(f,63,sizeof(f));
	f[0][0]=0;
	for(int i=0;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(f[i][j]<INF)
				for(int k=j+1;k<=n+1;k++)
					f[j][k]=min(f[j][k],f[i][j]+calc1(k+1,n+1,i+1,j)+calc2(j+1,k,j+1,k));
	long long res=INF;
	for(int i=0;i<=n;i++)
		res=min(res,f[i][n+1]);
	printf("%lld",res);
	return 0;
}

