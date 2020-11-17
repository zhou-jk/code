#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
const int N=1005;
const double eps=1e-12;
struct Point
{
	double x,y;
	Point(double _x=0,double _y=0)
	{
		x=_x,y=_y;
		return;
	}
	Point operator+(const Point &rhs)const
	{
		return {x+rhs.x,y+rhs.y};
	}
	Point operator-(const Point &rhs)const
	{
		return {x-rhs.x,y-rhs.y};
	}
	Point operator*(const double &rhs)const
	{
		return {x*rhs,y*rhs};
	}
	Point operator/(const double &rhs)const
	{
		return {x/rhs,y/rhs};
	}
	bool operator<(const Point &rhs)const
	{
		return x<rhs.x||(x==rhs.x&&y<rhs.y);
	}
	bool operator==(const Point &rhs)const
	{
		return x==rhs.x&&y==rhs.y;
	}
	friend double cross(const Point &a,const Point &b)
	{
		return a.x*b.y-a.y*b.x;
	}
};
struct Line
{
	Point a,b;
	friend bool segment_intersection(const Line &a,const Line &b)
	{
		double t1=cross(b.a-a.a,a.b-a.a),t2=cross(b.b-a.a,a.b-a.a);
		if((t1>0&&t2>0)||(t1<0&&t2<0)) return false;
		t1=cross(a.a-b.a,b.b-b.a),t2=cross(a.b-b.a,b.b-b.a);
		if((t1>0&&t2>0)||(t1<0&&t2<0)) return false;
		return true;
	}
	friend Point cross_point(const Line &a,const Line &b)
	{
		Point u=a.a-b.a,v=a.b-a.a,w=b.b-b.a;
		return a.a+v*cross(w,u)/cross(v,w);
	}
};
int n;
Line a[N];
set<Point>S;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf%lf%lf",&a[i].a.x,&a[i].a.y,&a[i].b.x,&a[i].b.y);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		set<Point>t;
		for(int j=1;j<=n;j++)
			if(i!=j)
				if(segment_intersection(a[i],a[j]))
				{
					Point p=cross_point(a[i],a[j]);
					if(abs(p.x-floor(p.x))<eps&&abs(p.y-floor(p.y))<eps)
					{
						S.insert(p);
						t.insert(p);
					}
				}
		ans+=abs(__gcd((long long)(a[i].b.x-a[i].a.x),(long long)(a[i].b.y-a[i].a.y)))+1-t.size();
	}
	ans+=S.size();
	printf("%lld",ans);
	return 0;
}
