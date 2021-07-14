#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=400005;
int T;
int n;
int a[N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    a[n+1]=0;
    long long ans=0;
    for(int i=1;i<=n;i++)
        if(a[i]>a[i-1]&&a[i]>a[i+1]) ans+=a[i]-max(a[i-1],a[i+1]),a[i]=max(a[i-1],a[i+1]);
    for(int i=1;i<=n+1;i++)
        ans+=abs(a[i]-a[i-1]);
    printf("%lld\n",ans);
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}