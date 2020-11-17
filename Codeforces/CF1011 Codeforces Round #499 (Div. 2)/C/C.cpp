#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005;
int n,m;
int a[N],b[N];
double calc(int k,double w)
{
	if(k==1)
	{
		printf("-1");
		exit(0);
	}
	return w+w*1.0/(k-1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	double s=m;
	s=calc(a[n],s);
	for(int i=n-1;i>=1;i--)
		s=calc(b[i+1],s),s=calc(a[i],s);
	s=calc(b[1],s);
	printf("%.10lf",s-m);
	return 0;
}
