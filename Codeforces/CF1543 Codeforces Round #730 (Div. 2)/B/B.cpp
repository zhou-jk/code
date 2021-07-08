#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int T;
int n;
int a[N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    long long ret=0;
    for(int i=1;i<=n;i++)
        ret+=a[i];
    int v=ret/n;
    for(int i=1;i<=n;i++)
        a[i]=v;
    ret-=(long long)v*n;
    for(int i=n;i>=n-ret+1;i--)
        a[i]++;
    long long sum=0;
    for(int i=1;i<=n;i++)
        sum+=a[i];
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        sum-=a[i];
        ans+=sum;
        ans-=(long long)a[i]*(n-i);
    }
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