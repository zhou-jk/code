#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MOD=1000000007;
int calc(long long n)
{
    int res=0;
    for(int i=2;(1ll<<i)<=n;i++)
    {
        long long val=1;
        long long l=1ll<<i,r=min((1ll<<(i+1))-1,n);
        for(int j=0;val<=r;j++)
        {
            long long ll=val,rr=min((__int128)val*i-1,(__int128)n);
            long long ql=max(l,ll),qr=min(r,rr);
            if(ql<=qr) res=(res+(qr-ql+1)%MOD*j)%MOD;
            if((__int128)val*i>r) break;
            val*=i;
        }
    }
    return res;
}
long long l,r;
void solve()
{
    cin>>l>>r;
    int ans=(calc(r)-calc(l-1)+MOD)%MOD;
    cout<<ans<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}