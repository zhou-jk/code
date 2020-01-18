#include <cstdio>
#include <algorithm>

using std::min;
using std::sort;

const int N=50000;
int x[N],y[N],tmp1[N],tmp2[N],k1[N],k2[N];
bool vis1[N],vis2[N];

bool cmp_x(int k1,int k2)
{
	return x[k1]<x[k2];
}

bool cmp_y(int k1,int k2)
{
	return y[k1]<y[k2];
}

int main()
{
	freopen("reduce.in","r",stdin); freopen("reduce.out","w",stdout);
	int n,ans=40000*40000;
	scanf("%d",&n);
	for (int i=0; i<n; ++i) scanf("%d%d",&x[i],&y[i]);
	for (int i=0; i<n; ++i) tmp1[i]=tmp2[i]=i;
	sort(tmp1,tmp1+n,cmp_x); sort(tmp2,tmp2+n,cmp_y);
	for (int i=0; i<n; ++i) k1[tmp1[i]]=k2[tmp2[i]]=i;
	for (int i=0; i<n; ++i)
	{
		int x_min,x_max,y_min,y_max;
		vis1[k1[i]]=true; vis2[k2[i]]=true;
		if (vis1[0]) x_min=x[tmp1[1]];
		else x_min=x[tmp1[0]];
		if (vis1[n-1]) x_max=x[tmp1[n-2]];
		else x_max=x[tmp1[n-1]];
		if (vis2[0]) y_min=y[tmp2[1]];
		else y_min=y[tmp2[0]];
		if (vis2[n-1]) y_max=y[tmp2[n-2]];
		else y_max=y[tmp2[n-1]];
		ans=min(ans,(x_max-x_min)*(y_max-y_min));
		vis1[k1[i]]=false; vis2[k2[i]]=false;
	}
	printf("%d",ans);
	return 0;
}