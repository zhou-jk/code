#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1005;
const int MOD=998244353;
int n,m;
int a[N];
int f[4][4];
vector<pair<int,int>>pos[N];
int tot;
struct Matrix
{
	static const int M=64;
	int n,m;
	long long mat[M][M];
	Matrix(int _n=0,int _m=0)
	{
		n=_n,m=_m;
		memset(mat,0,sizeof(mat));
		return;
	}
	void clear()
	{
		memset(mat,0,sizeof(mat));
		for(int i=0;i<=min(n,m);i++)
			mat[i][i]=1;
		return;
	}
	Matrix operator *(const Matrix &b)const
	{
		Matrix res(n,b.m);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=b.m;j++)
				for(int k=0;k<=m;k++)
					res.mat[i][j]=(res.mat[i][j]+mat[i][k]*b.mat[k][j]%MOD)%MOD;
		return res;
	}
};
int getmex(const vector<int> &val)
{
	static bool vis[N];
	for(int u:val)
		vis[u]=true;
	int ans=0;
	for(int i=0;;i++)
		if(!vis[i])
		{
			ans=i;
			break;
		}
	for(int u:val)
		vis[u]=false;
	return ans;
}
int convert(int x,int y,int z)
{
	return x|(y<<2)|(z<<4);
}
long long dp[N][4];
long long g[N][4];
Matrix A[40];
Matrix vector_ksm(const Matrix &a,int b)
{
	Matrix res=a;
	for(int i=30;i>=0;i--)
		if(b&(1<<i)) res=res*A[i];
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		pos[x].emplace_back(y,c);
	}
	for(int i=1;i<=n;i++)
		sort(pos[i].begin(),pos[i].end());
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			scanf("%d",&f[i][j]);
	tot=convert(3,3,3);
	A[0].n=A[0].m=tot;
	for(int x=0;x<=3;x++)
		for(int y=0;y<=3;y++)
			for(int z=0;z<=3;z++)
				for(int p=1;p<=3;p++)
				{
					vector<int>val;
					if(f[p][1]) val.emplace_back(x);
					if(f[p][2]) val.emplace_back(y);
					if(f[p][3]) val.emplace_back(z);
					int w=getmex(val);
					A[0].mat[convert(x,y,z)][convert(w,x,y)]++;
				}
	for(int i=1;i<=30;i++)
		A[i]=A[i-1]*A[i-1];
	for(int i=1;i<=n;i++)
	{
		Matrix T(0,tot);
		T.mat[0][convert(3,3,3)]=1;
		int pre=0;
		for(auto [now,p]:pos[i])
		{
			T=vector_ksm(T,now-1-(pre+1)+1);
			pre=now;
			Matrix G(tot,tot);
			for(int x=0;x<=3;x++)
				for(int y=0;y<=3;y++)
					for(int z=0;z<=3;z++)
					{
						vector<int>val;
						if(f[p][1]) val.emplace_back(x);
						if(f[p][2]) val.emplace_back(y);
						if(f[p][3]) val.emplace_back(z);
						int w=getmex(val);
						G.mat[convert(x,y,z)][convert(w,x,y)]++;
					}
			T=T*G;
		}
		T=vector_ksm(T,a[i]-(pre+1)+1);
		for(int j=0;j<=T.m;j++)
			g[i][j&3]=(g[i][j&3]+T.mat[0][j])%MOD;
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int x=0;x<=3;x++)
			for(int y=0;y<=3;y++)
				dp[i][x^y]=(dp[i][x^y]+dp[i-1][x]*g[i][y]%MOD)%MOD;
	printf("%lld",dp[n][0]);
	return 0;
}
