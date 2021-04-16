#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=105;
int n,x;
int a[N];
int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		if(sum>x)
		{
			printf("%d",i-1);
			return 0;
		}
	}
	if(sum==x) printf("%d",n);
	else printf("%d",n-1);
	return 0;
}