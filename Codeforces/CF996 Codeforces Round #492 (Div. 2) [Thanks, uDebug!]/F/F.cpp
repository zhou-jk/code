#include<iostream>
#include<cstdio>
using namespace std;
const int N=(1<<18)+5;
int n,r;
int c[N];
int main()
{
	scanf("%d%d",&n,&r);
	for(int i=0;i<(1<<n);i++)
		scanf("%d",&c[i]);
	long long sum=0;
	for(int i=0;i<(1<<n);i++)
		sum+=c[i];
	printf("%.7lf\n",(double)sum/(1<<n));
	while(r--)
	{
		int z,g;
		scanf("%d%d",&z,&g);
		sum-=c[z];
		c[z]=g;
		sum+=c[z];
		printf("%.7lf\n",(double)sum/(1<<n));
	}
	return 0;
}
