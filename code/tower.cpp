#include <cstdio>
#include <cstring>
#include <algorithm>

using std::sort;
using std::min;

const int N=50;
int x[N],y[N],d[N],ans[N];

int main()
{
	freopen("tower.in","r",stdin); freopen("tower.out","w",stdout);
	int n,sum;
	scanf("%d",&n);
	for (int i=0; i<n; i++) scanf("%d%d",&x[i],&y[i]);
	memset(ans,127,sizeof ans);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
		{
			for (int k=0; k<n; k++) d[k]=abs(x[k]-x[i])+abs(y[k]-y[j]);
			sort(d,d+n);
			sum=0;
			for (int k=0; k<n; k++) sum+=d[k],ans[k]=min(ans[k],sum);
		}
	for (int i=0; i<n; i++) printf("%d\n",ans[i]);
}