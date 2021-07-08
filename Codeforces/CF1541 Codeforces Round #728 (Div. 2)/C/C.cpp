#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int T;
int n;
int d[N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&d[i]);
    sort(d+1,d+n+1);
    long long sum=0;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=sum;
        ans-=(long long)(i-1)*d[i];
        sum+=d[i];
    }
    ans+=d[n];
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