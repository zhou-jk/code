//AC 
#include <cstdio>

const int N=50;
long long f[N+1];

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	f[0]=1;
	for (int i=1;i<=c;++i)
	{
		f[i]=f[i-1];
		if (i-2-a>=0) f[i]+=f[i-2-a]*b;
	}
	printf("%lld",f[c]);
	return 0;
}
