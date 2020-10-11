#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=205;
int n,m;
char s[N][N];
int a[N][N];
int sum[N][N];
int f[N][N][N][17];
int getsum(int l1,int l2,int r1,int r2)
{
	if(l1>l2) return -1;
	if(r1>r2) return -1;
	return sum[l2][r2]-sum[l1-1][r2]-sum[l2][r1-1]+sum[l1-1][r1-1];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='#') a[i][j]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
			for(int r=l;r<=m;r++)
			{
				int L=i,R=n,j=i-1;
				while(L<=R)
				{
					int mid=(L+R)/2;
					auto check=[=](int x)
					{
						return getsum(i,mid,l,r)==(mid-i+1)*(r-l+1)||getsum(i,mid,l,r)==0;
					};
					if(check(mid)) j=mid,L=mid+1;
					else R=mid-1;
				}
				f[i][l][r][0]=j;
			}
	if(f[1][1][m][0]>=n)
	{
		printf("%d",0);
		return 0;
	}
	for(int k=1;k<=ceil(log2(n))+ceil(log2(m));k++)
	{
		for(int i=1;i<=n;i++)
			for(int l=1;l<=m;l++)
				for(int r=l;r<=m;r++)
				{
					f[i][l][r][k]=f[i][l][r][k-1];
					f[i][l][r][k]=max(f[i][l][r][k],f[f[i][l][r][k-1]+1][l][r][k-1]);
					int L=l,R=r-1,j=i-1;
					while(L<=R)
					{
						int mid=(L+R)/2;
						int vl=f[i][l][mid][k-1],vr=f[i][mid+1][r][k-1];
						j=max(j,min(vl,vr));
						if(vl<vr) R=mid-1;
						else L=mid+1;
					}
					f[i][l][r][k]=max(f[i][l][r][k],j);
				}
		if(f[1][1][m][k]>=n)
		{
			printf("%d",k);
			return 0;
		}
	}
	return 0;
}
