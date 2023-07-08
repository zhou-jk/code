#include<iostream>
#include<cstdio>
using namespace std;
long long n;
void solve()
{
    scanf("%lld",&n);
    long long ans=0;
    while(n>0)
        ans+=n,n>>=1;
    printf("%lld\n",ans);
    return;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}