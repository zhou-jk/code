#include <cstdio>

int f(int a,int b)
{
	int ret=0;
	long long tmp=a;
	while (tmp<=b) ret++,tmp*=10;
	return ret;
}

int calc(int num)
{
	return f(1,num)+f(125,num)+f(2,num)+f(25,num)+f(5,num);
}

int main()
{
	freopen("magic.in","r",stdin); freopen("magic.out","w",stdout);
	int l,r;
	scanf("%d%d",&l,&r);
	printf("%d",calc(r)-calc(l-1));
	return 0;
}