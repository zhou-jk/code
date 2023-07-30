#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=500005;
const long long INF=4557430888798830399;
int n;
struct Design
{
    long long a;
    int b;
}d[N];
long long s[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld%d",&d[i].a,&d[i].b);
    sort(d+1,d+n+1,[=](const Design &x,const Design &y){return x.a<y.a;});
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+d[i].b;
    long long ans=-INF;
    long long pre=-INF;
    for(int i=1;i<=n;i++)
    {
        pre=max(pre,-s[i-1]+d[i].a);
        ans=max(ans,s[i]-d[i].a+pre);
    }
    printf("%lld",ans);
    return 0;
}