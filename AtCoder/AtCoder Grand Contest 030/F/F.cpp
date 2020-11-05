#include<iostream>
#include<cstdio>
using namespace std;
const int N=305;
const int MOD=1000000007;
int n;
int a[N+N];
bool vis[N+N],book[N+N];
int b[N+N],m;
long long f[N+N][N+N][N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n+n;i++)
		scanf("%d",&a[i]);
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++)
		if(a[2*i-1]==-1&&a[2*i]==-1) cnt1++;
		else if(a[2*i-1]==-1&&a[2*i]!=-1) cnt2++,book[a[2*i]]=true;
		else if(a[2*i-1]!=-1&&a[2*i]==-1) cnt2++,book[a[2*i-1]]=true;
		else if(a[2*i-1]!=-1&&a[2*i]!=-1) vis[a[2*i-1]]=vis[a[2*i]]=true;
	for(int i=n+n;i>=1;i--)
		if(!vis[i]) b[++m]=i;
	f[0][0][0]=1;
	for(int i=1;i<=m;i++)
		for(int j=0;j<=cnt1+cnt2;j++)
			for(int k=0;k<=cnt2;k++)
				if(f[i-1][j][k])
				{
					if(book[b[i]])
					{
						f[i][j][k+1]=(f[i][j][k+1]+f[i-1][j][k])%MOD;
						if(j-1>=0) f[i][j-1][k]=(f[i][j-1][k]+f[i-1][j][k])%MOD;
					}
					else
					{
						f[i][j+1][k]=(f[i][j+1][k]+f[i-1][j][k])%MOD;
						if(j-1>=0) f[i][j-1][k]=(f[i][j-1][k]+f[i-1][j][k])%MOD;
						if(k-1>=0) f[i][j][k-1]=(f[i][j][k-1]+f[i-1][j][k]*k%MOD)%MOD;
					}
				}
	long long ans=f[m][0][0];
	for(int i=1;i<=cnt1;i++)
		ans=ans*i%MOD;
	printf("%lld",ans);
	return 0;
}
