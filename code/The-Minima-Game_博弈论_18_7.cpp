//POI2010 luogu-P3507
#include <cstdio>
#include <algorithm>

using std::sort;
using std::max;

const int N=1000000;
int num[N];

int main()
{
	int n;
	long long ans=0;
	scanf("%d",&n);
	for (int i=0; i<n; ++i) scanf("%d",&num[i]);
	sort(num,num+n);
	for (int i=0; i<n; ++i) ans=max(ans,num[i]-ans);
	printf("%lld",ans);
	return 0;
}