#include <cstdio>

const int N=500000;
int a[N],b[N],c[N<<1],q[N<<1];

int main()
{
	freopen("travel.in","r",stdin); freopen("travel.out","w",stdout);
	int n,m,sum=0,l=0,r=0;
	bool flag=false;
	scanf("%d%d",&n,&m);
	for (int i=0; i<n; i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		sum+=a[i];
	}
	a[0]=m-sum;
	for (int i=1; i<n; i++) c[i+n]=c[i]=c[i-1]-(b[i-1]-a[i]);
	for (int i=1; i<n*2; i++)
	{
		if (l<r&&i-q[l]>n) l++;
		if (i>=n&&c[i]>=c[q[l]]) printf("%d ",i-n+1),flag=true;
		while (l<r&&c[i]>c[q[r-1]]) r--;
		q[r++]=i;
	}
	if (!flag) puts("-1");
	return 0;
}