#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
struct Point
{
    int x,y;
}p[N];
long long ans;
void solve(int l,int r)
{
    if(l==r) return;
    int mid=(l+r)/2;
    solve(l,mid);
    solve(mid+1,r);
    static Point bl[N],br[N];
    int totl=0,totr=0;
    for(int i=l;i<=mid;i++)
        bl[++totl]=p[i];
    for(int i=mid+1;i<=r;i++)
        br[++totr]=p[i];
    sort(bl+1,bl+totl+1,[](const Point &a,const Point &b){return a.y==b.y?a.x<b.x:a.y<b.y;});
    sort(br+1,br+totr+1,[](const Point &a,const Point &b){return a.y==b.y?a.x<b.x:a.y<b.y;});
    static int stkl[N],stkr[N];
    int topl=0,topr=0;
    br[0].y=-1;
    for(int i=1,j=1;i<=totr;i++)
    {
        while(j<=totl&&bl[j].y<br[i].y)
        {
            while(topl>0&&bl[stkl[topl]].x<=bl[j].x) topl--;
            stkl[++topl]=j;
            j++;
        }
        while(topr>0&&br[stkr[topr]].x>=br[i].x) topr--;
        int l=1,r=topl,p=topl+1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(bl[stkl[mid]].y>br[stkr[topr]].y) p=mid,r=mid-1;
            else l=mid+1;
        }
        ans+=topl-p+1;
        stkr[++topr]=i;
    }
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&p[i].x,&p[i].y);
    sort(p+1,p+n+1,[](const Point &a,const Point &b){return a.x==b.x?a.y<b.y:a.x<b.x;});
    solve(1,n);
    printf("%lld",ans);
    return 0;
}