#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<random>
#include<map>
#include<vector>
#include<functional>
#include<iomanip>
#include<algorithm>
using namespace std;
namespace Geometry
{
    const double eps=1e-10;
    const double PI=acos(-1);
    const double INF=1e18;
    bool equal(double a,double b)
    {
        return abs(a-b)<eps;
    }
    bool less(double a,double b)
    {
        return b-a>=eps;
    }
    bool greater(double a,double b)
    {
        return a-b>=eps;
    }
    bool less_equal(double a,double b)
    {
        return less(a,b)||equal(a,b);
    }
    bool greater_equal(double a,double b)
    {
        return greater(a,b)||equal(a,b);
    }
    class Point
    {
    public:
        double x,y;
        Point(){x=0,y=0;}
        Point(const double &_x,const double &_y):x(_x),y(_y) {}
        friend Point operator * (const Point &a,const double &b)
        {
            return Point(a.x*b,a.y*b);
        }
        friend Point operator * (const double &a,const Point &b)
        {
            return Point(a*b.x,a*b.y);
        }
        friend Point operator / (const Point &a,const double &b)
        {
            return Point(a.x/b,a.y/b);
        }
        friend Point operator + (const Point &a,const Point &b)
        {
            return Point(a.x+b.x,a.y+b.y);
        }
        friend Point operator - (const Point &a,const Point &b)
        {
            return Point(a.x-b.x,a.y-b.y);
        }
        friend double cross(const Point &a,const Point &b)
        {
            return a.x*b.y-a.y*b.x;
        }
        friend double dot(const Point &a,const Point &b)
        {
            return a.x*b.x+a.y*b.y;
        }
        friend bool operator == (const Point &a,const Point &b)
        {
            return equal(a.x,b.x)&&equal(a.y,b.y);
        }
        friend bool operator < (const Point &a,const Point &b)
        {
            if(equal(a.x,b.x)) return less(a.y,b.y);
            else return less(a.x,b.x);
        }
        friend bool operator > (const Point &a,const Point &b)
        {
            if(equal(a.x,b.x)) return greater(a.y,b.y);
            else return greater(a.x,b.x);
        }
        friend bool operator <= (const Point &a,const Point &b)
        {
            if(equal(a.x,b.x)) return less_equal(a.y,b.y);
            else return less_equal(a.x,b.x);
        }
        friend bool operator >= (const Point &a,const Point &b)
        {
            if(equal(a.x,b.x)) return greater_equal(a.y,b.y);
            else return greater_equal(a.x,b.x);
        }
        double length()const
        {
            return sqrt(x*x+y*y);
        }
        Point unit()const
        {
            return *this/length();
        }
        double angle()const
        {
            return atan2(y,x);
        }
        friend double angle(const Point &a,const Point &b)
        {
            return atan2(cross(a,b),dot(a,b));
        }
        Point rotate(const double &theta)const
        {
            return Point(x*cos(theta)-y*sin(theta),x*sin(theta)+y*cos(theta));
        }
        friend istream &operator>>(istream &in,Point &obj)
        {
            in>>obj.x>>obj.y;
            return in;
        }
        friend ostream &operator<<(ostream &out,const Point &obj)
        {
            out<<obj.x<<" "<<obj.y;
            return out;
        }
    };
    double distance(const Point &a,const Point &b)
    {
        return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    }
    enum Direction
    {
        COUNTER_CLOCKWISE,
        CLOCKWISE,
        ONLINE_BACK,
        ONLINE_FRONT,
        ON_SEGMENT
    };
    istream& operator>>(istream& in,Direction& direction)
    {
        string value;
        in>>value;
        if(value=="COUNTER_CLOCKWISE") direction=COUNTER_CLOCKWISE;
        else if(value=="CLOCKWISE") direction=CLOCKWISE;
        else if(value=="ONLINE_BACK") direction=ONLINE_BACK;
        else if(value=="ONLINE_FRONT") direction=ONLINE_FRONT;
        else if(value=="ON_SEGMENT") direction=ON_SEGMENT;
        else in.setstate(ios::failbit);
        return in;
    }
    ostream& operator<<(ostream& out,const Direction& direction)
    {
        if(direction==COUNTER_CLOCKWISE) out<<"COUNTER_CLOCKWISE";
        else if(direction==CLOCKWISE) out<<"CLOCKWISE";
        else if(direction==ONLINE_BACK) out<<"ONLINE_BACK";
        else if(direction==ONLINE_FRONT) out<<"ONLINE_FRONT";
        else if(direction==ON_SEGMENT) out<<"ON_SEGMENT";
        return out;
    }
    class Line
    {
    public:
        Point a,b;
        Line(){}
        Line(const Point &_a,const Point &_b):a(_a),b(_b){}
        Point projection(const Point &p)const
        {
            return a+(b-a).unit()*(dot(p-a,b-a)/(b-a).length());
        }
        Point reflection(const Point &p)const
        {
            return projection(p)*2-p;
        }
        Direction direction(const Point &p)const
        {
            double t=cross(b-a,p-a);
            if(greater(t,0)) return COUNTER_CLOCKWISE;
            if(less(t,0)) return CLOCKWISE;
            double l1=dot(p-a,b-a);
            if(less(l1,0)) return ONLINE_BACK;
            double l2=dot(b-a,b-a);
            if(l1>l2) return ONLINE_FRONT;
            else return ON_SEGMENT;
        }
        double distance(const Point &p)const
        {
            Point u=projection(p);
            if(direction(u)==ON_SEGMENT) return Geometry::distance(u,p);
            else return min(Geometry::distance(a,p),Geometry::distance(b,p));
        }
        friend istream &operator>>(istream &in,Line &obj)
        {
            in>>obj.a>>obj.b;
            return in;
        }
        friend ostream &operator<<(ostream &out,const Line &obj)
        {
            out<<obj.a<<" "<<obj.b;
            return out;
        }
    };
    bool parallel(const Line &x,const Line &y)
    {
        return equal(cross(x.b-x.a,y.b-y.a),0);
    }
    bool orthogonal(const Line &x,const Line &y)
    {
        return equal(dot(x.b-x.a,y.b-y.a),0);
    }
    Point cross_point(const Line &x,const Line &y)
    {
        Point u=x.a-y.a,v=x.b-x.a,w=y.b-y.a;
        double t=cross(w,u)/cross(v,w);
        return x.a+t*v;
    }
    int sig(double x)
    {
        return greater(x,0)-less(x,0);
    }
    bool intersection(const Line &x,const Line &y)
    {
        if(x.direction(y.a)==ON_SEGMENT||x.direction(y.b)==ON_SEGMENT||y.direction(x.a)==ON_SEGMENT||y.direction(x.b)==ON_SEGMENT) return true;
        return sig(cross(x.b-x.a,y.a-x.a))*sig(cross(x.b-x.a,y.b-x.a))<0&&sig(cross(y.b-y.a,x.a-y.a))*sig(cross(y.b-y.a,x.b-y.a))<0;
    }
    double distance(const Line &x,const Line &y)
    {
        if(intersection(x,y)) return 0;
        else return min({x.distance(y.a),x.distance(y.b),y.distance(x.a),y.distance(x.b)});
    }
}
using namespace Geometry;
const int N=105;
int n,S;
Line l[N];
Point p[N*2];
int tot;
map<Point,int>pos;
Point s[5];
bool check(Line L)
{
    for(int i=1;i<=4;i++)
        if(L.direction(s[i])!=COUNTER_CLOCKWISE) return false;
    return true;
}
double f[N*2][N*2];
int main()
{
    scanf("%d%d",&n,&S);
    for(int i=1;i<=n;i++)
        scanf("%lf%lf%lf%lf",&l[i].a.x,&l[i].a.y,&l[i].b.x,&l[i].b.y);
    s[1]=Point(S,S),s[2]=Point(S,-S),s[3]=Point(-S,S),s[4]=Point(-S,-S);
    for(int i=1;i<=n;i++)
        p[++tot]=l[i].a,p[++tot]=l[i].b;
    for(int i=1;i<=4;i++)
        p[++tot]=s[i];
    sort(p+1,p+tot+1);
    tot=unique(p+1,p+tot+1)-p-1;
    for(int i=1;i<=tot;i++)
        pos[p[i]]=i;
    for(int i=1;i<=tot;i++)
        for(int j=1;j<=tot;j++)
            if(i!=j)
            {
                if(check(Line(p[i],p[j]))) f[i][j]=distance(p[i],p[j]);
                else f[i][j]=INF;
            }
            else 
    return 0;
}