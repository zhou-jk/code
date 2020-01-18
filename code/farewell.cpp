#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using std::priority_queue;
using std::vector;
using std::pair;
using std::greater;
using std::max;

const int N=100000;
long long a[N],b[N],b1[N],b2[N],c[N];

int main()
{
	freopen("farewell.in","r",stdin); freopen("farewell.out","w",stdout);
	int l,m,n;
	priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > a1;
	scanf("%d%d%d",&l,&n,&m);
	for (int i=0; i<n; ++i) scanf("%lld",&a[i]),a1.push(pair<long long,int>(a[i],i));
	for (int i=0; i<m; ++i) scanf("%lld",&b[i]);
	for (int i=0; i<l; ++i)
	{
		pair<long long,int> tmp=a1.top();
		c[i]=tmp.first;
		a1.pop(); a1.push(pair<long long,int>(tmp.first+a[tmp.second],tmp.second));
		//printf("%lld ",c[i]);
	}
	//puts("");
	long long ans=c[l-1];
	memset(b1,-1,sizeof b1);
	for (int i=l-1; ~i; --i)
	{
		long long tmp1=100000000000000000,tmp2,tmp3=-1;
		for (int j=0; j<m; ++j)
		{
			if (~b1[j])
			{
				if (c[i]+b[j]<=b1[j])
				{
					tmp1=-1;
					b1[j]=c[i];
					break;
				}
				else if (b2[j]+b[j]<tmp1) tmp1=b2[j]+b[j],tmp2=j;
			}
			else if (c[i]+b[j]<tmp1) tmp1=c[i]+b[j],tmp2=j,tmp3=c[i];
		}
		//printf("%lld\n",tmp1);
		if (tmp1!=-1)
		{
			ans=max(ans,tmp1);
			b2[tmp2]=tmp1;
			if (tmp3!=-1) b1[tmp2]=tmp3;
		}
	}
	printf("%lld",ans);
	return 0;
}
