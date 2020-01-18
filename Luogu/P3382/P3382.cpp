#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double eps=1e-6;
const int N=14;
int n;
double l,r;
double a[N];
double f(double x)
{
	double sum=0;
	for(int i=n;i>=0;i--)
		sum=sum*x+a[i];
	return sum; 
}
int main()
{
	scanf("%d%lf%lf",&n,&l,&r);
	for(int i=n;i>=0;i--)
		scanf("%lf",&a[i]);
	while(fabs(l-r)>=eps)
	{
		double mid1=l+(r-l)/3,mid2=r-(r-l)/3;
		if(f(mid2)>f(mid1)) l=mid1;
		else r=mid2;
	}
	printf("%.5lf",l);
	return 0;
}
