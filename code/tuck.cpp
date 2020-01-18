#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;

const int N=30,A=1000,B=20000,C=330;
int f[A+C][B+C+1],a[N],b[N];

int main()
{
	freopen("tuck.in","r",stdin); freopen("tuck.out","w",stdout);
	int n,m,ans=2000000000;
	scanf("%d%d",&n,&m);
	for (int i=0; i<n; i++) scanf("%d%d",&a[i],&b[i]);
	memset(f,63,sizeof f);
	f[0][B+m]=0;
	for (int i=0; i<A; i++)
		for (int j=m; j>0; j--)
		{
			//printf("%d %d %d\n",i,j,f[i][B+j]);
			f[i][B+j-i]=min(f[i][B+j-i],f[i][B+j]+1);
			//puts("^");
			for (int k=0; k<n; k++)
				f[i+b[k]][B+j-i*a[k]]=min(f[i+b[k]][B+j-i*a[k]],f[i][B+j]+a[k]);
			//puts("%");
		}
	//puts("#");
	for (int i=0; i<A+C; i++)
		for (int j=0; j<=B; j++) /*printf("%d %d %d",i,j,f[i][j]),*/ans=min(ans,f[i][j]);
	printf("%d",ans);
	return 0;
}
