#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
struct Point
{
    int x,y;
    Point(){x=0,y=0;}
    Point(const int &_x,const int &_y):x(_x),y(_y) {}
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
int va,vb;
Point a,b,c;
int distance(const Point &a,const Point &b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}
void solve()
{
    cin>>va>>vb;
    cin>>a>>b>>c;
    int l=min(a.x,b.x),r=max(a.x,b.x),d=min(a.y,b.y),u=max(a.y,b.y);
    Point p(max(l,min(r,c.x)),max(d,min(u,c.y)));
    double ta=(double)distance(a,p)/va,tb=(double)distance(b,p)/vb;
    double ans=(double)distance(a,c)/va;
    if(ta<tb) ans=min(ans,(double)distance(b,c)/vb);
    else
    {
        double t=(double)distance(a,b)/(va+vb);
        ans=min(ans,t+(distance(a,c)-va*t)/vb);
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