#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n,k;
int a[N];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int d=k;
	for(int i=1;i<=n;i++)
		d=__gcd(d,a[i]);
	printf("%d\n",k/d);
	for(int i=0;i<k/d;i++)
		printf("%d ",i*d);
	return 0;
}
