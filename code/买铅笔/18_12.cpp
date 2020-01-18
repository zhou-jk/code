//AC
#include <cstdio>

const int N=3;

int main()
{
	int c,ans=1E9;
	scanf("%d",&c);
	for (int i=0;i<N;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int tmp=b*(c/a+(bool)(c%a));
		if (tmp<ans) ans=tmp;
	}
	printf("%d",ans);
	return 0;
}
