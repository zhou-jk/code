#include <cstdio>

const int N=100000;
int a[N];

int main()
{
	freopen("seq.in","r",stdin); freopen("seq.out","w",stdout);
	int n,sum=0,tmp=0,ans=0;
	scanf("%d",&n);
	for (int i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if (sum<0) puts("-1");
	else printf("%d",ans);
	return 0;
}