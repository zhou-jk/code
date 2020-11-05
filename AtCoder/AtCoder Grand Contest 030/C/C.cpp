#include<iostream>
#include<cstdio>
using namespace std;
int k;
int n;
int main()
{
	scanf("%d",&k);
	if(k==1)
	{
		printf("1\n");
		printf("1");
		return 0;
	}
	n=(k+3)/4*2;
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int v=(i+j)%n+1;
			if(i&1) v+=n;
			if(v>k) v-=n;
			printf("%d ",v);
		}
		printf("\n");
	}
	return 0;
}
