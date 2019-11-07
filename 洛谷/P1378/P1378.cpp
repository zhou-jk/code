#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double PI=3.1415926535;
bool book[7];
double x[7],y[7],r[7];
double xa,ya,xb,yb;
double res;
int n;
inline double count(int a,int b)
{
    return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
double calc(int i)
{
	double ans=min(min(abs(x[i]-xa),abs(x[i]-xb)),min(abs(y[i]-ya),abs(y[i]-yb)));
	for(int j=1;j<=n;j++)
	    if(i!=j&&book[j]) ans=min(ans,max(count(i,j)-r[j],0.0));
	return ans;
}
void dfs(int k,double sum)
{
	if(k>n)
	{
		res=max(res,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!book[i])
		{
			r[i]=calc(i);
			book[i]=true;
			dfs(k+1,sum+r[i]*r[i]*PI);
			book[i]=false;
		}
	}
    return;
}
int main()
{
	scanf("%d",&n);
	scanf("%lf%lf%lf%lf",&xa,&ya,&xb,&yb);
	for(int i=1;i<=n;i++)
	    scanf("%lf%lf",&x[i],&y[i]);
	dfs(1,0);
	printf("%.0lf",abs(xa-xb)*abs(ya-yb)-res);
    return 0;
}