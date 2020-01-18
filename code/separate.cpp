#include <cstdio>
#include <cstring>
#include <algorithm>

using std::sort;
using std::min;

const int N=5000,M=5000;
int a[N];
unsigned int f[N][M];

int main()
{
	freopen("separate.in","r",stdin); freopen("separate.out","w",stdout);
	int t,n,m;
	unsigned int tmp=(unsigned int)(1<<31)-1;
	scanf("%d",&t);
	for (int i=0; i<t; i++)
	{
		scanf("%d%d",&n,&m);
		for (int j=0; j<n; j++) scanf("%d",&a[j]);
		sort(a,a+n);
		for (int j=0; j<n; j++)
		{
			f[j][0]=(a[j]-a[0])*(a[j]-a[0]);
			for (int k=1; k<m; k++)
			{
				f[j][k]=tmp;
				for (int p=0; p<j; p++)
					f[j][k]=min(f[j][k],f[p][k-1]+(a[j]-a[p+1])*(a[j]-a[p+1]));
			}
		}
		printf("Case%d:%d\n",i+1,f[n-1][m-1]);
	}
	return 0;
}