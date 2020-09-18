#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n;
int d[N];
long long c[N];
int main()
{
	scanf("%d",&n);
	long long sumc=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%lld",&d[i],&c[i]);
		sumc+=c[i],sum+=d[i]*c[i];
	}
	printf("%lld",(sum-1)/9+sumc-1);
	return 0;
}
