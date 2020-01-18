#include <cstdio>
#include <algorithm>

using std::max;

const int N=100000;
int num[N+2],q[N+2];

int main()
{
	int n,l,r;
	long long ans;
	while (scanf("%d",&n)!=EOF&&n)
	{
		l=r=ans=0;
		num[0]=-10000;
		q[r++]=0;
		for (int i=1; i<=n; i++) scanf("%d",&num[i]);
		num[++n]=-1000;
		for (int i=1; i<=n; i++)
		{
			while (l<r&&num[i]<=num[q[r-1]]) ans=max(ans,(long long)num[q[r-1]]*(i-1-q[r-2])),r--;
			q[r++]=i;
		}
		printf("%lld\n",ans);
	}
	return 0;
}