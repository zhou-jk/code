//AC
#include <cstdio>

const int N=7;

int main()
{
	int maxn=7,maxk=0;
	for (int i=1;i<=N;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if (a+b>maxn)
		{
			maxn=a+b;
			maxk=i; 
		}
	}
	printf("%d",maxk);
	return 0;
}
