#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
const int N=800005;
typedef pair<int,int> Point;
#define x first
#define y second
int n;
Point p[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        p[i]={x+y,x-y};
    }
    long long delta=0,ans=0;
    multiset<long long>l,r;
    l.insert(0),r.insert(0);
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++)
    {
        delta+=p[i].x-p[i-1].x;
        if(p[i].y<*l.rbegin()-delta)
        {
            ans+=(*l.rbegin()-delta)-p[i].y;
            l.insert(p[i].y+delta),l.insert(p[i].y+delta);
            r.insert(*l.rbegin()-delta-delta),l.erase(--l.end());
        }
        else if(p[i].y>*r.begin()+delta)
        {
            ans+=p[i].y-(*r.begin()+delta);
            r.insert(p[i].y-delta),r.insert(p[i].y-delta);
            l.insert(*r.begin()+delta+delta),r.erase(r.begin());
        }
        else l.insert(p[i].y+delta),r.insert(p[i].y-delta);
    }
    ans/=2;
    printf("%lld",ans);
    return 0;
}