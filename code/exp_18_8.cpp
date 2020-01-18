#include <cstdio>
#include <queue>
#include <algorithm>

using std::priority_queue;
using std::sort;

const int N=10000;
struct Gas_Sta
{
	int dist,num;
} gas_sta[N];

bool cmp(Gas_Sta a,Gas_Sta b)
{
	return a.dist<b.dist;
}

int main()
{
	freopen("exp.in","r",stdin); freopen("exp.out","w",stdout);
	int n,len,s;
	priority_queue<int> heap;
	scanf("%d",&n);
	for (int i=0; i<n; ++i) scanf("%d%d",&gas_sta[i].dist,&gas_sta[i].num);
	scanf("%d%d",&len,&s);
	for (int i=0; i<n; ++i) gas_sta[i].dist=len-gas_sta[i].dist;
	sort(gas_sta,gas_sta+n,cmp);
	int i=0,ans;
	for (ans=0; s<len; s+=heap.top(),/*printf("%d\n",s),*/heap.pop(),++ans)
	{
		for (; i<n&&gas_sta[i].dist<=s; ++i) heap.push(gas_sta[i].num);
		if (heap.empty()) break;
	}
	if (s<len) puts("-1");
	else printf("%d",ans);
	return 0;
}