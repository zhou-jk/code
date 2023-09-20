#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=3005;
const double PI=acos(-1);
int n;
struct Point
{
    int x,y;
    int c;
    Point():x(0),y(0),c(0){}
    Point(const int &_x,const int &_y,const int _c):x(_x),y(_y),c(_c){}
    double angle()const
    {
        return atan2(y,x);
    }
}p[N];
int c[2][3];
long long calc(int op,int color)
{
    long long res=1;
    for(int col=0;col<=2;col++)
        if(col!=color) res*=c[op][col];
    return res;
};
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].c);
    long long ans=0;
    for(int u=1;u<=n;u++)
    {
        vector<Point>pos;
        for(int i=1;i<=n;i++)
            if(i!=u) pos.emplace_back(p[i].x-p[u].x,p[i].y-p[u].y,p[i].c);
        sort(pos.begin(),pos.end(),[=](const Point &a,const Point &b)
        {
            double x=a.angle(),y=b.angle();
            if(x<=0) x+=PI;
            if(y<=0) y+=PI;
            return x<y;
        });
        memset(c,0,sizeof(c));
        static int bl[N];
        for(int i=0;i<(int)pos.size();i++)
        {
            if(pos[i].y<0||(pos[i].y==0&&pos[i].x>0)) bl[i]=0;
            else bl[i]=1;
            c[bl[i]][pos[i].c]++;
        }
        for(int i=0;i<(int)pos.size();i++)
        {
            c[bl[i]][pos[i].c]--;
            bl[i]^=1;
            ans+=calc(0,pos[i].c)*calc(1,p[u].c);
            ans+=calc(1,pos[i].c)*calc(0,p[u].c);
            c[bl[i]][pos[i].c]++;
        }
    }
    ans/=4;
    printf("%lld",ans);
    return 0;
}