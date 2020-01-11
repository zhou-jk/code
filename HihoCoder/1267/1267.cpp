#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;
const int N=105;
const int MOD=1000000007;
int n,m;
int a[N],b[N];
bitset<N> G[N],A[N];
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
int calc()
{
	int c=1,r=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=c;j<=n;j++)
			if(A[j][i])
			{
				swap(A[j],A[c]);
				break;
			}
		if(A[c][i])
		{
			for(int j=c+1;j<=n;j++)
				if(A[j][i]) A[j]^=A[c];
			c++;
		}
		else r++;
	}
	for(int i=c+1;i<=n;i++)
		if(A[i][m+1]==1) return 0;
	return ksm(2,r);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		G[a[i]][i]=G[b[i]][i]=1;
	}
	long long ans=0;
	for(int i=1;i<=m;i++)
		for(int j=i;j<=m;j++)
		{
			for(int k=1;k<=n;k++)
			{
				A[k]=G[k];
				if(A[k][i]) A[k][m+1]=A[k][m+1]^1,A[k][i]=0;
				if(A[k][j]) A[k][m+1]=A[k][m+1]^1,A[k][j]=0;
			}
			ans=(ans+2*ksm(4,MOD-2)%MOD*calc()%MOD)%MOD;
		}
	printf("%lld",ans);
	return 0;
}
