#include <cstdio>
#include <algorithm>

using std::min;

const int N=100,L=0,R=100010,oo=2000000000;
int a[N],b[N],sm[N],pm[N],sv[N],pv[N],n,m;

int calc(const int a,const int b)
{
	if (a<0) return 0;
	int ret=a/b;
	if (a%b) ret++;
	return ret;
}

bool check(const int num)
{
	int tmp1=0,tmp2,tmp3;
	for (int i=0; i<n; i++)
	{
		tmp2=a[i]*num-b[i];
		tmp3=oo;
		for (int j=0; sv[i]*(j-1)<tmp2; j++)
			tmp3=min(tmp3,pv[i]*j+pm[i]*calc(tmp2-sv[i]*j,sm[i]));
		tmp1+=tmp3;
		if (tmp1>m) return false;
	}
	return true;
}

int main()
{
	freopen("party.in","r",stdin); freopen("party.out","w",stdout);
	int l,r,mid;
	scanf("%d %d",&n,&m);
	for (int i=0; i<n; i++)
		scanf("%d %d %d %d %d %d",&a[i],&b[i],&sm[i],&pm[i],&sv[i],&pv[i]);
	l=L; r=R;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%d",r);
	return 0;
}