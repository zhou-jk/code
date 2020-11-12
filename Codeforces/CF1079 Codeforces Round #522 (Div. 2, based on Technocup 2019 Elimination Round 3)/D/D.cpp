#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int a,b,c;
struct Point
{
	double x,y;
	Point(double _x=0,double _y=0)
	{
		x=_x,y=_y;
		return;
	}
	bool operator<(const Point &b)const
	{
		return x<b.x||(x==b.x&&y<b.y);
	}
	bool operator==(const Point &b)const
	{
		return x==b.x&&y==b.y;
	}
};
double calcx(double a,double b,double c,double y)
{
	return (-b*y-c)/a;
}
double calcy(double a,double b,double c,double x)
{
	return (-a*x-c)/b;
}
double dis(Point a,Point b)
{
	return sqrt((b.y-a.y)*(b.y-a.y)+(b.x-a.x)*(b.x-a.x));
}
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	Point A,B;
	scanf("%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y);
	double x1=calcx(a,b,c,A.y),x2=calcx(a,b,c,B.y),y1=calcy(a,b,c,A.x),y2=calcy(a,b,c,B.x);
	vector<Point>pos;
	if(min(A.x,B.x)<=x1&&x1<=max(A.x,B.x)) pos.emplace_back(x1,A.y);
	if(min(A.x,B.x)<=x2&&x2<=max(A.x,B.x)) pos.emplace_back(x2,B.y);
	if(min(A.y,B.y)<=y1&&y1<=max(A.y,B.y)) pos.emplace_back(A.x,y1);
	if(min(A.y,B.y)<=y2&&y2<=max(A.y,B.y)) pos.emplace_back(B.x,y2);
	sort(pos.begin(),pos.end());
	pos.erase(unique(pos.begin(),pos.end()),pos.end());
	double ans=abs(A.x-B.x)+abs(A.y-B.y);
	for(Point x:pos)
		for(Point y:pos)
		{
			if((A.x==x.x||A.y==x.y)&&(B.x==y.x||B.y==y.y)) ans=min(ans,dis(A,x)+dis(x,y)+dis(y,B));
		}
	printf("%.7lf",ans);
	return 0;
}
