#include <cstdio>
#include <algorithm>

using std::min;
using std::max;

const int N=10000,M=100000;
int x[M],p[M];
double tmp[N];

int main()
{
	freopen("assemble.in","r",stdin); freopen("assemble.out","w",stdout);
	int n,m,l=1000000000,r=-1000000000;
	double tmp1=1e19,ans;
	scanf("%d%d",&n,&m);
	for (int i=0; i<m; ++i)
	{
		scanf("%d%d",&x[i],&p[i]);
		--p[i];
		l=min(l,x[i]); r=max(r,x[i]);
	}
	for (double i=l; i<=r; i+=0.00001)
	{
		double sum=0;
		for (int j=0; j<n; ++j) tmp[j]=1e19;
		for (int j=0; j<m; ++j)
			tmp[p[j]]=min(tmp[p[j]],(x[j]-i)*(x[j]-i));
		for (int j=0; j<n; ++j) sum+=tmp[j];
		if (sum<tmp1) tmp1=sum,ans=i;
	}
	printf("%.4lf",ans);
	return 0;
}