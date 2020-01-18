//AC
#include <cstdio>

const int N=10000;
int x1[N],y1[N],x2[N],y2[N];

int main()
{
	int n,x,y,ans=-1;
	scanf("%d",&n);
	for (int i=0;i<n;++i)
	{
		int tmp1,tmp2;
		scanf("%d%d%d%d",x1+i,y1+i,&tmp1,&tmp2);
		x2[i]=x1[i]+tmp1; y2[i]=y1[i]+tmp2;
	}
	scanf("%d%d",&x,&y);
	for (int i=0;i<n;++i)
		if (x1[i]<=x&&y1[i]<=y&&x2[i]>=x&&y2[i]>=y) ans=i+1;
	printf("%d",ans);
	return 0;
}
