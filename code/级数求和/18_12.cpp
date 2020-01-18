//AC
#include <cstdio>

int main()
{
	int k,ans=1;
	scanf("%d",&k);
	for (double s=0;s<=k;++ans) s+=(double)1/ans;
	printf("%d",ans-1);
	return 0;
}
