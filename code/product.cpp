#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;

const int N=5,M=100000;
struct Node
{
	int k,s;
} tmp,q[N][M];
int t[N][M],f[M][N],sum[N][M],l[N],r[N];


int main()
{
	freopen("product.in","r",stdin); freopen("product.out","w",stdout);
	int tmp,m,n,a,b,ans=2e9;
	scanf("%d%d%d%d",&m,&n,&a,&b);
	for (int i=0; i<n; i++)
	{
		scanf("%d",&t[i][0]);
		sum[i][0]=t[i][0];
		for (int j=1; j<m; j++)
		{
			scanf("%d",&t[i][j]);
			sum[i][j]=sum[i][j-1]+t[i][j];
		}
	}
	for (int i=0; i<n; i++)
	{
		f[0][i]=t[i][0];
		q[i][r[i]++]= {0,0};
	}
	for (int i=1; i<m; i++)
		for (int j=0; j<n; j++)
		{
			f[i][j]=tmp=2e9;
			while (l[j]<r[j]&&q[j][l[j]].k<=i-b) l[j]++;
			if (l[j]<r[j]) f[i][j]=q[j][l[j]].s+sum[j][i];
			for (int k=0; k<n; k++)
				if (k!=j) tmp=min(tmp,f[i-1][k]+a+t[j][i]);
			f[i][j]=min(f[i][j],tmp);
			while (l[j]<r[j]&&q[j][r[j]-1].s>tmp-sum[j][i]) r[j]--;
			q[j][r[j]++]= {i,tmp-sum[j][i]};
		}
	for (int i=0; i<n; i++) ans=min(ans,f[m-1][i]);
	printf("%d",ans);
	return 0;
}