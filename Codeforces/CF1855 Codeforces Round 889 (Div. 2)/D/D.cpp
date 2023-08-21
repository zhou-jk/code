#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;
const int N=100005;
int n;
int a[N];
long long sum[N];
bitset<N*2>f,g;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    g.set();
    f[1]=1;
    for(int i=1;i<=n;i++)
        f|=(f&g)<<a[i],g[i]=0;
    long long ans=0;
    for(int i=1;i<=n*2;i++)
        if(f[i]) ans=max(ans,sum[min(i,n)]-(i-1));
    printf("%lld",ans);
    return 0;
}