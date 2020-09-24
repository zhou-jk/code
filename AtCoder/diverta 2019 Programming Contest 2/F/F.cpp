#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=15;
const int a[N]={0,1,2,4,7,12,20,29,38,52,73};
int n,p[N];
long long g[N][N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
			p[j]=j;
		long long M=0;
		do
		{
			long long s=0;
			for(int j=1;j<i;j++)
				s+=g[p[j]][p[j+1]];
			M=max(M,s);
		}
		while(next_permutation(p+1,p+i+1));
		for(int j=1;j<i;j++)
			g[i][j]=g[j][i]=(M+1)*a[j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%lld ",g[i][j]);
		printf("\n");
	}
	return 0;
}
