//POJ-2823
#include <cstdio>

const int N=1000000;
int num[N],q[N];

int main()
{
	int n,m,l=0,r=0;
	scanf("%d%d",&n,&m);
	for (int i=0; i<n; i++) scanf("%d",&num[i]);
	for (int i=0; i<n; i++)
	{
		if (l<r&&i-q[l]==m) l++;
		while (l<r&&num[i]<=num[q[r-1]]) r--;
		q[r++]=i;
		if (i>=m-1) printf("%d ",num[q[l]]);
	}
	puts("");
	l=r=0;
	for (int i=0; i<n; i++)
	{
		if (l<r&&i-q[l]==m) l++;
		while (l<r&&num[i]>=num[q[r-1]]) r--;
		q[r++]=i;
		if (i>=m-1) printf("%d ",num[q[l]]);
	}
	return 0;
}