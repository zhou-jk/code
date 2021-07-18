#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=100005;
int n;
struct Point
{
    int x,y;
}p[N*2];
int a[N],b[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
        scanf("%d%d",&p[i].x,&p[i].y);
    long long ans=0;
    for(int i=1;i<=2*n;i++)
        if(p[i].y>=2)
        {
            if(1<=p[i].x&&p[i].x<=n) a[p[i].x]++,ans+=p[i].y-2;
            else if(p[i].x<1) a[1]++,ans+=p[i].y-2+1-p[i].x;
            else if(p[i].x>n) a[n]++,ans+=p[i].y-2+p[i].x-n;
        }
        else
        {
            if(1<=p[i].x&&p[i].x<=n) b[p[i].x]++,ans+=1-p[i].y;
            else if(p[i].x<1) b[1]++,ans+=1-p[i].y+1-p[i].x;
            else if(p[i].x>n) b[n]++,ans+=1-p[i].y+p[i].x-n;
        }
    for(int i=1;i<=n;i++)
        a[i]--,b[i]--;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>0&&b[i]<0)
        {
            int v=min(a[i],-b[i]);
            ans+=v,a[i]-=v,b[i]+=v;
        }
        if(a[i]<0&&b[i]>0)
        {
            int v=min(-a[i],b[i]);
            ans+=v,a[i]+=v,b[i]-=v;
        }
        ans+=abs(a[i]),a[i+1]+=a[i],a[i]=0;
        ans+=abs(b[i]),b[i+1]+=b[i],b[i]=0;
    }
    printf("%lld",ans);
    return 0;
}