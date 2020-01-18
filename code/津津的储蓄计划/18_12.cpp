//AC
#include <cstdio>

const int N=12;

int main()
{
	int s=0,ans=0;
	for (int i=1;i<=N;++i)
	{
		int a;
		scanf("%d",&a);
		s+=300-a;
		if (s<0)
		{
			printf("%d",-i);
			return 0;
		}
		ans+=s/100*100;
		s%=100;
	}
	printf("%d",ans+ans/5+s);
	return 0;
}
