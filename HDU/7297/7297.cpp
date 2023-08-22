#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=10005;
const double e=exp(1);
int n;
double sum[N];
void init(int n=10000)
{
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+1.0/i;
    return;
}
double calc(int k)
{
    if(k<=0) return 0;
    return k*(sum[n-1]-sum[k-1]);
}
void solve()
{
    cin>>n;
    if(n<3)
    {
        cout<<0<<"\n";
        return;
    }
    int k1=n/e;
    int k0=k1-1,k2=k1+1;
    int ans=k1;
    if(calc(k0)>calc(ans)) ans=k0;
    if(calc(k2)>calc(ans)) ans=k2;
    cout<<ans<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}