#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
using namespace std;
const int N=2505,K=105;
int n,m,k;
long long s[N];
vector<int>G[N];
bitset<N>f[K][N];
int mx[N],smx[N],ssmx[N];
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	k++;
	for(int i=2;i<=n;i++)
		scanf("%lld",&s[i]);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].emplace_back(y);
		G[y].emplace_back(x);
	}
	for(int u=1;u<=n;u++)
		f[0][u][u]=1;
	for(int i=1;i<=k;i++)
		for(int u=1;u<=n;u++)
		{
			f[i][u]=f[i-1][u];
			for(int v:G[u])
				f[i][u]|=f[i-1][v];
		}
	for(int B=2;B<=n;B++)
	{
		bitset<N>S=f[k][1]&f[k][B];
		if(S.any())
		{
			for(int A=2;A<=n;A++)
				if(A!=B&&S[A])
				{
					if(s[A]>=s[mx[B]]) ssmx[B]=smx[B],smx[B]=mx[B],mx[B]=A;
					else if(s[A]>=s[smx[B]]) ssmx[B]=smx[B],smx[B]=A;
					else if(s[A]>=s[ssmx[B]]) ssmx[B]=A;
				}
		}
	}
	long long ans=0;
	int a[3],d[3];
	for(int B=2;B<=n;B++)
		if(mx[B]>0)
			for(int C=2;C<=n;C++)
				if(B!=C&&mx[C]>0&&f[k][B][C])
				{
					int cnta=0,cntd=0;
					if(mx[B]!=C) a[++cnta]=mx[B];
					if(smx[B]>0&&smx[B]!=C) a[++cnta]=smx[B];
					if(ssmx[B]>0&&ssmx[B]!=C) a[++cnta]=ssmx[B];
					if(cnta==0) continue;
					if(mx[C]!=B) d[++cntd]=mx[C];
					if(smx[C]>0&&smx[C]!=B) d[++cntd]=smx[C];
					if(ssmx[C]>0&&ssmx[C]!=B) d[++cntd]=ssmx[C];
					if(cntd==0) continue;
					if(a[1]!=d[1])
					{
						int A=a[1],D=d[1];
						ans=max(ans,s[A]+s[B]+s[C]+s[D]);
					}
					else
					{
						for(int i=1;i<=cnta;i++)
							for(int j=1;j<=cntd;j++)
								if(a[i]!=d[j]) ans=max(ans,s[a[i]]+s[B]+s[C]+s[d[j]]);
					}
				}
	printf("%lld",ans);
	return 0;
}