#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n,m;
int a[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	double ans=-1;
	for(int i=1,k=1;i<=n;i++)
	{
		int j=i+1;
		while(k+1<=n&&a[k+1]-a[i]<=m) k++;
		if(i<j&&j<k) ans=max(ans,(double)(a[k]-a[j])/(a[k]-a[i]));
	}
	printf("%.10lf",ans);
	return 0;
}
