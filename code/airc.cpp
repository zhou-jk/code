#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;

const int N=10000,N1=N>>1;
int a[N+1],b[N+1],f[N1+1][N1+1];

int main()
{
	freopen("airc.in","r",stdin); freopen("airc.out","w",stdout);
	int n,n1;
	scanf("%d",&n);
	n1=n>>1;
	for (int i=1; i<=n; i++) scanf("%d%d",&a[i],&b[i]);
	memset(f,63,sizeof f); f[0][0]=0;
	for (int i=1; i<=n1; i++) f[i][0]=f[i-1][0]+b[i];
	for (int i=1; i<=n1; i++)
		for (int j=1; j<=i; j++)
			f[i][j]=min(f[i-1][j]+b[i+j],f[i][j-1]+a[i+j]);
	printf("%d",f[n1][n1]);
	return 0;
}