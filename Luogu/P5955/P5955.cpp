#include<iostream>
#include<cstdio>
#include<functional>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
struct Point
{
    int x,y;
    int quadrant()const
    {
        if(x>0&&y>=0) return 1;
        else if(x<=0&&y>0) return 2;
        else if(x<0&&y<=0) return 3;
        else if(x>=0&&y<0) return 4;
        else return 0;
    }
    friend long long cross(const Point &a,const Point &b)
    {
        return (long long)a.x*b.y-(long long)a.y*b.x;
    }
}p[N+N];
bool cmp(const Point &a,const Point &b)
{
    int x=a.quadrant(),y=b.quadrant();
    if(x!=y) return x<y;
    else return cross(a,b)>0;
}
int main()
{
    scanf("%d",&n);
    long long sx=0,sy=0;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        p[i]={x,y};
        p[i+n]={-x,-y};
        if(y<0||(y==0&&x<0)) sx+=x,sy+=y;
    }
    sort(p+1,p+n+n+1,cmp);
    long long ans=sx*sx+sy*sy;
    for(int i=1;i<=n+n;i++)
    {
        sx+=p[i].x,sy+=p[i].y;
        ans=max(ans,sx*sx+sy*sy);
    }
    printf("%lld",ans);
    return 0;
}