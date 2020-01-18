#include <cstdio>
#include <algorithm>

using std::max;

const int N_NODE=100000;
int b[N_NODE+1];
long long a[N_NODE+1];


int main()
{
	freopen("mowlawn.in","r",stdin); freopen("mowlawn.out","w",stdout);
	int n,m,num,l=0,r=0;
	long long sum=0;
	scanf("%d%d",&n,&m);
	a[0]=0; b[0]=-1;
	r=1;
	for (int i=0; i<n; i++)
	{
		scanf("%d",&num);
		sum+=num;
		//for (int j=l; j<r; j++) printf("%lld %d  ",a[j],b[j]);
		//puts("#");
		while (a[r-1]+sum<=a[l]+sum-num) r--;
		//for (int j=l; j<r; j++) printf("%lld %d  ",a[j],b[j]);
		//puts("%");
		a[r]=a[l]-num; b[r]=i; r++;
		//for (int j=l; j<r; j++) printf("%lld %d  ",a[j],b[j]);
		//puts("*");
		while (b[l]<i-m) l++;
	}
	printf("%lld",a[l]+sum);
	return 0;
}