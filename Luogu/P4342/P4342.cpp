#include<iostream>
#include<cstdio>
using namespace std;
const int N=205;
const int INF=1061109567;
int n;
int a[N],c[N];
int f[N][N],g[N][N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char ch;
		for(ch=getchar();ch!='t'&&ch!='x';ch=getchar());
		c[i]=c[i+n]=ch=='t';
		scanf("%d",&a[i]);
		a[i+n]=a[i];
	}
	for(int i=1;i<=n*2;i++)
		for(int j=1;j<=n*2;j++) 
			f[i][j]=INF,g[i][j]=-INF;
	for(int i=1;i<=n*2;i++)
		f[i][i]=g[i][i]=a[i];
	for(int len=1;len<=n;len++)
		for(int l=1;l<=n*2&&len+l-1<=n*2;l++)
		{
			int r=len+l-1;
			for(int k=l;k<r;k++)
				if(c[k+1])
				{
					f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]);
					g[l][r]=max(g[l][r],g[l][k]+g[k+1][r]);
				}
				else
				{
					f[l][r]=min(f[l][r],f[l][k]*f[k+1][r]);
					f[l][r]=min(f[l][r],g[l][k]*f[k+1][r]);
					f[l][r]=min(f[l][r],f[l][k]*g[k+1][r]);
					g[l][r]=max(g[l][r],g[l][k]*g[k+1][r]);
					g[l][r]=max(g[l][r],f[l][k]*f[k+1][r]);
				}
		}
	int res=-INF;
	for(int l=1,r=l+n-1;l<=n;l++,r++) 
		if(res<g[l][r]) res=g[l][r];
	printf("%d\n",res);
	for(int l=1,r=l+n-1;l<=n;l++,r++) 
		if(g[l][r]==res) printf("%d ",l);
	return 0;
}
