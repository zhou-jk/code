#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=3005;
const double PI=acos(-1);
int n,L;
double t[N];
int main()
{
	scanf("%d%d",&n,&L);
	for(int i=1;i<=n;i++)
		scanf("%lf",&t[i]);
	double ansx=0,ansy=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
	    {
			int cnt=j-i-1;
			ansx+=cos((t[i]+t[j])/L*PI)*(n-2*cnt-2),ansy+=sin((t[i]+t[j])/L*PI)*(n-2*cnt-2);
		}
	ansx/=1LL*n*(n-1)*(n-2)/6,ansy/=1LL*n*(n-1)*(n-2)/6;
	printf("%.15lf %.15lf",ansx,ansy);
	return 0;
}
