#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
using namespace std;
const double PI=acos(-1);
struct Point
{
    double x,y;
    Point(){x=0,y=0;}
    Point(const double &_x,const double &_y):x(_x),y(_y) {}
    friend Point operator + (const Point &a,const Point &b)
    {
        return Point(a.x+b.x,a.y+b.y);
    }
    friend Point operator / (const Point &a,const double &b)
    {
        return Point(a.x/b,a.y/b);
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
void solve()
{
    Point a,b,p;
    int v,t;
    cin>>p;
    cin>>a;
    cin>>b;
    cin>>v>>t;
    double r=v*t;
    double pa=distance(p,a);
    double ans=0;
    if(r>=pa) ans=PI*r*r;
    else
    {
        double ab=distance(a,b);
        double ad=sqrt(pa*pa-r*r);
        double pc=distance(p,(a+b)/2);
        if(r<=pc)
        {
            double angle=asin(ad/pa)+asin(ab/2/pa);
            ans=ad*r+pc*ab/2+(PI-angle)*r*r;
        }
        else
        {
            double angle=asin(ad/pa);
            ans=ad*r*2+(PI-2*angle)*r*r;
        }
    }
    cout<<fixed<<setprecision(10)<<ans<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}