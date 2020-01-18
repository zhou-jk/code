//POJ 2976
#include <cstdio>
#include <algorithm>

using namespace std;

const int N=1000,NUM=1000000000;
int a[N],b[N];
double c[N];

bool cmp(double a,double b)
{
	return a>b;
}

int main()
{
	int n,m;
	double l,r,mid,sum;
	while (scanf("%d%d",&n,&m)==2&&(n||m))
	{
		for (int i=0; i<n; i++) scanf("%d",&a[i]);
		for (int i=0; i<n; i++) scanf("%d",&b[i]);
		l=0,r=NUM;
		while (r-l>1e-4)
		{
			mid=(l+r)*0.5;
			for (int i=0; i<n; i++) c[i]=a[i]-mid*b[i];
			sort(c,c+n,cmp);
			sum=0;
			for (int i=0; i<n-m; i++) sum+=c[i];
			if (sum>=0) l=mid;
			else r=mid;
		}
		printf("%.0f\n",l*100);
	}
	return 0;
}