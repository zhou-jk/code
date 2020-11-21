#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double dis(double x1,double y1,double x2,double y2)
{
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
int main()
{
	double R,x1,y1,x2,y2;
	scanf("%lf%lf%lf%lf%lf",&R,&x1,&y1,&x2,&y2);
	if(dis(x1,y1,x2,y2)>R)
	{
		printf("%.7lf %.7lf %.7lf",x1,y1,R);
		return 0;
	}
	if(x1==x2&&y1==y2)
	{
		printf("%.7lf %.7lf %.7lf",x1-R/2.0,y1,R/2.0);
		return 0;
	}
	double kx=(x1-x2)/dis(x1,y1,x2,y2),ky=(y1-y2)/dis(x1,y1,x2,y2);
	double dx=x1+R*kx,dy=y1+R*ky;
	double xap=(dx+x2)/2,yap=(dy+y2)/2,d=dis(xap,yap,x2,y2);
	printf("%.7lf %.7lf %.7lf",xap,yap,d);
	return 0;
}
